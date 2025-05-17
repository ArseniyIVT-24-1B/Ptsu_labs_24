#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QWidget>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTabWidget>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDoubleValidator>
#include <QWebEngineView>
#include <QWebChannel>
#include <QFile>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

class MapBridge : public QObject {
    Q_OBJECT
public:
    explicit MapBridge(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void coordinatesPicked(double lat, double lng);

public slots:
    void onMapClicked(double lat, double lng) {
        emit coordinatesPicked(lat, lng);
    }
};

class StockViewer : public QMainWindow {
    Q_OBJECT

public:
    StockViewer(QWidget *parent = nullptr) : QMainWindow(parent) {
        // Настройка основного окна
        setWindowTitle("Монитор акций нефтегазовых компаний");
        setMinimumSize(1000, 800);

        // Создание вкладок
        QTabWidget *tabWidget = new QTabWidget(this);
        QWidget *mainTab = new QWidget();
        QWidget *weatherTab = new QWidget();
        QWidget *oilTab = new QWidget();

        // Главная вкладка
        QVBoxLayout *mainLayout = new QVBoxLayout(mainTab);

        // Группа для предупреждений
        QGroupBox *warningGroup = new QGroupBox("Анализ цен на нефть");
        QVBoxLayout *warningLayout = new QVBoxLayout(warningGroup);
        warningLabel = new QLabel("Анализ рыночной ситуации...");
        warningLayout->addWidget(warningLabel);

        // Группа для погоды
        QGroupBox *weatherStatusGroup = new QGroupBox("Анализ погоды");
        QFormLayout *weatherStatusLayout = new QFormLayout(weatherStatusGroup);
        weatherStatusLabel = new QLabel("Загрузка...");
        weatherStatusLayout->addRow(weatherStatusLabel);

        // Группа для акций
        QGroupBox *stocksGroup = new QGroupBox("Акции");
        QVBoxLayout *stocksLayout = new QVBoxLayout(stocksGroup);

        // График акций Газпрома
        gazpromChartView = new QChartView();
        gazpromChartView->setRenderHint(QPainter::Antialiasing);
        gazpromChartView->setMinimumHeight(200);
        stocksLayout->addWidget(gazpromChartView);

        QFormLayout *stocksFormLayout = new QFormLayout();
        gazpromLabel = new QLabel("Загрузка...");
        gazpromChangeLabel = new QLabel();
        stocksFormLayout->addRow("Газпром:", gazpromLabel);
        stocksFormLayout->addRow("Изменение:", gazpromChangeLabel);
        stocksLayout->addLayout(stocksFormLayout);

        updateLabel = new QLabel("Последнее обновление: -");
        updateLabel->setAlignment(Qt::AlignRight);

        mainLayout->addWidget(warningGroup);
        mainLayout->addWidget(weatherStatusGroup);
        mainLayout->addWidget(stocksGroup);
        mainLayout->addWidget(updateLabel);

        // Вкладка нефти
        QVBoxLayout *oilTabLayout = new QVBoxLayout(oilTab);
        QGroupBox *oilGroup = new QGroupBox("Нефть Brent");
        QVBoxLayout *oilGroupLayout = new QVBoxLayout(oilGroup);

        // График цен на нефть
        oilChartView = new QChartView();
        oilChartView->setRenderHint(QPainter::Antialiasing);
        oilChartView->setMinimumHeight(200);
        oilGroupLayout->addWidget(oilChartView);

        QFormLayout *oilFormLayout = new QFormLayout();
        oilPriceLabel = new QLabel("Загрузка...");
        oilChangeLabel = new QLabel();
        oilFormLayout->addRow("Цена:", oilPriceLabel);
        oilFormLayout->addRow("Изменение:", oilChangeLabel);
        oilGroupLayout->addLayout(oilFormLayout);

        oilTabLayout->addWidget(oilGroup);

        // Вкладка погоды
        QVBoxLayout *weatherTabLayout = new QVBoxLayout(weatherTab);

        // Группа для координат и карты
        QGroupBox *mapGroup = new QGroupBox("Выбор местоположения");
        QVBoxLayout *mapLayout = new QVBoxLayout(mapGroup);

        // Поля для координат
        QHBoxLayout *coordLayout = new QHBoxLayout();
        latitudeEdit = new QLineEdit("55.7558");
        longitudeEdit = new QLineEdit("37.6176");
        QDoubleValidator *validator = new QDoubleValidator(-90, 90, 6, this);
        latitudeEdit->setValidator(validator);
        longitudeEdit->setValidator(validator);

        coordLayout->addWidget(new QLabel("Широта:"));
        coordLayout->addWidget(latitudeEdit);
        coordLayout->addWidget(new QLabel("Долгота:"));
        coordLayout->addWidget(longitudeEdit);

        QPushButton *updateWeatherButton = new QPushButton("Обновить погоду");
        connect(updateWeatherButton, &QPushButton::clicked, this, &StockViewer::fetchWeather);
        coordLayout->addWidget(updateWeatherButton);

        mapLayout->addLayout(coordLayout);

        // Карта
        webView = new QWebEngineView();
        webView->setMinimumHeight(400);
        mapLayout->addWidget(webView);

        weatherTabLayout->addWidget(mapGroup);

        // Группа для погоды
        QGroupBox *weatherGroup = new QGroupBox("Погода");
        QFormLayout *weatherLayout = new QFormLayout(weatherGroup);
        weatherTempLabel = new QLabel("Загрузка...");
        weatherConditionLabel = new QLabel();
        weatherWindLabel = new QLabel();

        weatherLayout->addRow("Температура:", weatherTempLabel);
        weatherLayout->addRow("Состояние:", weatherConditionLabel);
        weatherLayout->addRow("Ветер:", weatherWindLabel);

        weatherTabLayout->addWidget(weatherGroup);
        weatherTabLayout->addStretch();

        tabWidget->addTab(mainTab, "Главная");
        tabWidget->addTab(oilTab, "Нефть");
        tabWidget->addTab(weatherTab, "Погода");
        setCentralWidget(tabWidget);

        // Настройка карты
        setupMap();

        // Настройка сетевого менеджера
        networkManager = new QNetworkAccessManager(this);
        connect(networkManager, &QNetworkAccessManager::finished, this, &StockViewer::onNetworkReply);

        // Таймер для обновления данных
        updateTimer = new QTimer(this);
        connect(updateTimer, &QTimer::timeout, this, &StockViewer::fetchAllData);
        updateTimer->start(5 * 60 * 1000); // 5 минут

        // Инициализация графиков
        initCharts();

        // Загрузка исторических данных
        loadHistoricalData();

        // Первоначальная загрузка данных
        fetchAllData();

        // Создание меню
        createMenu();
    }

private:
    void setupMap() {
        // Создаем мост для взаимодействия с JavaScript
        MapBridge *bridge = new MapBridge(this);
        QWebChannel *channel = new QWebChannel(this);
        channel->registerObject("bridge", bridge);

        // Устанавливаем webChannel ДО загрузки страницы
        webView->page()->setWebChannel(channel);

        // Загружаем HTML с картой
        QFile htmlFile(":/map.html");
        if (htmlFile.open(QIODevice::ReadOnly)) {
            QString html = htmlFile.readAll();
            htmlFile.close();
            webView->setHtml(html, QUrl("qrc:/"));
        } else {
            qDebug() << "Не удалось загрузить HTML карты";
        }

        // Подключаем сигнал от моста
        connect(bridge, &MapBridge::coordinatesPicked, this, [this](double lat, double lng) {
            latitudeEdit->setText(QString::number(lat, 'f', 6));
            longitudeEdit->setText(QString::number(lng, 'f', 6));
            fetchWeather();
        });
    }

    void initCharts() {
        // График для акций Газпрома
        gazpromChart = new QChart();
        gazpromChart->setTitle("Динамика акций Газпрома");
        gazpromChart->legend()->hide();

        QDateTimeAxis *gazpromAxisX = new QDateTimeAxis;
        gazpromAxisX->setTitleText("Время");
        gazpromAxisX->setFormat("dd.MM hh:mm");
        gazpromChart->addAxis(gazpromAxisX, Qt::AlignBottom);

        QValueAxis *gazpromAxisY = new QValueAxis;
        gazpromAxisY->setTitleText("Цена (руб)");
        gazpromChart->addAxis(gazpromAxisY, Qt::AlignLeft);

        gazpromChartView->setChart(gazpromChart);

        // График для цен на нефть
        oilChart = new QChart();
        oilChart->setTitle("Динамика цен на нефть Brent");
        oilChart->legend()->hide();

        QDateTimeAxis *oilAxisX = new QDateTimeAxis;
        oilAxisX->setTitleText("Время");
        oilAxisX->setFormat("dd.MM hh:mm");
        oilChart->addAxis(oilAxisX, Qt::AlignBottom);

        QValueAxis *oilAxisY = new QValueAxis;
        oilAxisY->setTitleText("Цена ($)");
        oilChart->addAxis(oilAxisY, Qt::AlignLeft);

        oilChartView->setChart(oilChart);
    }

    void updateGazpromChart(double price, const QDateTime &timestamp) {
        static QLineSeries *gazpromSeries = nullptr;

        if (gazpromSeries == nullptr) {
            gazpromSeries = new QLineSeries();
            gazpromChart->addSeries(gazpromSeries);
            gazpromSeries->attachAxis(gazpromChart->axes(Qt::Horizontal)[0]);
            gazpromSeries->attachAxis(gazpromChart->axes(Qt::Vertical)[0]);
        }

        gazpromSeries->append(timestamp.toMSecsSinceEpoch(), price);

        // Обновляем диапазон осей X (время)
        gazpromChart->axes(Qt::Horizontal)[0]->setRange(
            timestamp.addSecs(-24 * 3600).toMSecsSinceEpoch(),
            timestamp.addSecs(3600).toMSecsSinceEpoch()
            );

        // Автомасштабирование по оси Y

        if (!gazpromSeries->points().empty()) {
            auto yAxis = static_cast<QValueAxis*>(gazpromChart->axes(Qt::Vertical)[0]);



            double minY = gazpromSeries->points().first().y();
            double maxY = gazpromSeries->points().first().y();

            for (const QPointF &point : gazpromSeries->points()) {
                if (point.y() < minY) minY = point.y();
                if (point.y() > maxY) maxY = point.y();
            }

            // Добавляем немного места сверху и снизу
            double padding = (maxY - minY) * 1;
            yAxis->setRange(minY - padding, maxY + padding);
        }
    }

    void updateOilChart(double price, const QDateTime &timestamp) {
        static QLineSeries *oilSeries = nullptr;

        if (oilSeries == nullptr) {
            oilSeries = new QLineSeries();
            oilChart->addSeries(oilSeries);
            oilSeries->attachAxis(oilChart->axes(Qt::Horizontal)[0]);
            oilSeries->attachAxis(oilChart->axes(Qt::Vertical)[0]);
        }

        oilSeries->append(timestamp.toMSecsSinceEpoch(), price);

        // Обновляем диапазон осей X (время)
        oilChart->axes(Qt::Horizontal)[0]->setRange(
            timestamp.addSecs(-24 * 3600).toMSecsSinceEpoch(),
            timestamp.addSecs(3600).toMSecsSinceEpoch()
            );

        // Автомасштабирование по оси Y
        if (!oilSeries->points().empty()) {
            auto yAxis = static_cast<QValueAxis*>(oilChart->axes(Qt::Vertical)[0]);
            double minY = oilSeries->points().first().y();
            double maxY = oilSeries->points().first().y();

            for (const QPointF &point : oilSeries->points()) {
                if (point.y() < minY) minY = point.y();
                if (point.y() > maxY) maxY = point.y();
            }

            // Добавляем немного места сверху и снизу
            double padding = (maxY - minY) * 0.1;
            yAxis->setRange(minY - padding, maxY + padding);
        }
    }

    void saveDataToFile(double gazpromPrice, double oilPrice, const QDateTime &timestamp) {
        if (gazpromPrice == 0 && oilPrice == 0) return;

        QFile file("stock_data.csv");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);

            // Если файл пустой, добавляем заголовок
            if (file.size() == 0) {
                out << "Timestamp,Gazprom Price,Oil Price\n";
            }

            if (gazpromPrice != 0 && oilPrice != 0) {
                out << timestamp.toString(Qt::ISODate) << ","
                    << gazpromPrice << ","
                    << oilPrice << "\n";
            }
            else if (gazpromPrice != 0) {
                out << timestamp.toString(Qt::ISODate) << ","
                    << gazpromPrice << ",\n";
            }
            else if (oilPrice != 0) {
                out << timestamp.toString(Qt::ISODate) << ",,"
                    << oilPrice << "\n";
            }

            file.close();
        }
    }

    void loadHistoricalData() {
        QFile file("stock_data.csv");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return;
        }

        QTextStream in(&file);
        bool firstLine = true;

        QLineSeries *gazpromSeries = new QLineSeries();
        QLineSeries *oilSeries = new QLineSeries();

        while (!in.atEnd()) {
            QString line = in.readLine();
            if (firstLine) {
                firstLine = false;
                continue; // Пропускаем заголовок
            }

            QStringList parts = line.split(",");
            if (parts.size() < 3) continue;

            QDateTime timestamp = QDateTime::fromString(parts[0], Qt::ISODate);

            if (!parts[1].isEmpty()) {
                double gazpromPrice = parts[1].toDouble();
                gazpromSeries->append(timestamp.toMSecsSinceEpoch(), gazpromPrice);
            }

            if (!parts[2].isEmpty()) {
                double oilPrice = parts[2].toDouble();
                oilSeries->append(timestamp.toMSecsSinceEpoch(), oilPrice);
            }
        }

        file.close();

        // Добавляем данные на графики
        if (!gazpromSeries->points().empty()) {
            gazpromChart->addSeries(gazpromSeries);
            gazpromSeries->attachAxis(gazpromChart->axes(Qt::Horizontal)[0]);
            gazpromSeries->attachAxis(gazpromChart->axes(Qt::Vertical)[0]);

            // Устанавливаем диапазон по последним 24 часам
            QDateTime now = QDateTime::currentDateTime();
            gazpromChart->axes(Qt::Horizontal)[0]->setRange(
                now.addSecs(-24 * 3600).toMSecsSinceEpoch(),
                now.addSecs(3600).toMSecsSinceEpoch()
                );

            // Настраиваем ось Y
            auto yAxis = static_cast<QValueAxis*>(gazpromChart->axes(Qt::Vertical)[0]);
            double minY = gazpromSeries->points().first().y();
            double maxY = gazpromSeries->points().first().y();

            for (const QPointF &point : gazpromSeries->points()) {
                if (point.y() < minY) minY = point.y();
                if (point.y() > maxY) maxY = point.y();
            }

            double padding = (maxY - minY) * 0.1;
            yAxis->setRange(minY - padding, maxY + padding);
        }

        if (!oilSeries->points().empty()) {
            oilChart->addSeries(oilSeries);
            oilSeries->attachAxis(oilChart->axes(Qt::Horizontal)[0]);
            oilSeries->attachAxis(oilChart->axes(Qt::Vertical)[0]);

            // Устанавливаем диапазон по последним 24 часам
            QDateTime now = QDateTime::currentDateTime();
            oilChart->axes(Qt::Horizontal)[0]->setRange(
                now.addSecs(-24 * 3600).toMSecsSinceEpoch(),
                now.addSecs(3600).toMSecsSinceEpoch()
                );

            // Настраиваем ось Y
            auto yAxis = static_cast<QValueAxis*>(oilChart->axes(Qt::Vertical)[0]);
            double minY = oilSeries->points().first().y();
            double maxY = oilSeries->points().first().y();

            for (const QPointF &point : oilSeries->points()) {
                if (point.y() < minY) minY = point.y();
                if (point.y() > maxY) maxY = point.y();
            }

            double padding = (maxY - minY) * 0.1;
            yAxis->setRange(minY - padding, maxY + padding);
        }
    }

private slots:
    void fetchAllData() {
        fetchWeather();
        fetchGazprom();
        fetchOil();
    }

    void fetchWeather() {
        double latitude = latitudeEdit->text().toDouble();
        double longitude = longitudeEdit->text().toDouble();

        QUrl weatherUrl(QString("https://api.open-meteo.com/v1/forecast?latitude=%1&longitude=%2&current_weather=true").arg(latitude).arg(longitude));
        QNetworkRequest weatherRequest(weatherUrl);
        networkManager->get(weatherRequest);
    }

    void fetchGazprom() {
        QNetworkRequest gazpromRequest(QUrl("https://iss.moex.com/iss/engines/stock/markets/shares/boards/TQBR/securities/GAZP.json?iss.meta=off&iss.only=marketdata"));
        networkManager->get(gazpromRequest);
    }

    void fetchOil() {
        QNetworkRequest oilRequest(QUrl("https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=BZ&apikey=4XY1XHTVCWPPC9F2"));
        networkManager->get(oilRequest);
    }

    void onNetworkReply(QNetworkReply *reply) {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Ошибка сети:" << reply->errorString();
            reply->deleteLater();
            return;
        }

        QByteArray data = reply->readAll();
        QString url = reply->url().toString();

        if (url.contains("open-meteo")) {
            QJsonDocument doc = QJsonDocument::fromJson(data);
            processWeatherData(doc.object());
        }
        else if (url.contains("moex.com")) {
            QJsonDocument doc = QJsonDocument::fromJson(data);
            processGazpromData(doc.object());
        }
        else if (url.contains("alphavantage")) {
            QJsonDocument doc = QJsonDocument::fromJson(data);
            processOilData(doc.object());
        }

        reply->deleteLater();
    }

    void processGazpromData(const QJsonObject &json) {
        QJsonArray marketdata = json["marketdata"].toObject()["data"].toArray();
        if (marketdata.isEmpty()) {
            gazpromLabel->setText("Ошибка получения данных");
            return;
        }

        QJsonArray gazpromData = marketdata[0].toArray();
        double price = gazpromData[12].toDouble();
        double change = gazpromData[13].toDouble();
        double percentChange = gazpromData[14].toDouble();

        QString color = change >= 0 ? "green" : "red";
        QString sign = change >= 0 ? "+" : "";

        gazpromLabel->setText(QString("<span style='font-size:12pt;'>%1 ₽</span>").arg(price, 0, 'f', 2));
        gazpromChangeLabel->setText(QString("<span style='color:%1;'>%2%3 ₽ (%4%)</span>")
                                        .arg(color)
                                        .arg(sign)
                                        .arg(change, 0, 'f', 2)
                                        .arg(percentChange, 0, 'f', 2));

        lastGazpromPrice = price;
        lastGazpromChange = percentChange;

        QDateTime now = QDateTime::currentDateTime();
        updateGazpromChart(price, now);
        saveDataToFile(price, 0, now);

        updateMarketWarning();
        updateLastUpdateTime();
    }

    void processOilData(const QJsonObject &json) {
        if (json.contains("error")) {
            oilPriceLabel->setText("Ошибка получения данных");
            return;
        }

        QJsonObject globalQuote = json["Global Quote"].toObject();

        double price = globalQuote["05. price"].toString().toDouble();
        double change = globalQuote["09. change"].toString().toDouble();
        double percentChange = globalQuote["10. change percent"].toString().replace("%", "").toDouble();

        QString color = change >= 0 ? "green" : "red";
        QString sign = change >= 0 ? "+" : "";

        oilPriceLabel->setText(QString("<span style='font-size:12pt;'>%1 $</span>").arg(price, 0, 'f', 2));
        oilChangeLabel->setText(QString("<span style='color:%1;'>%2%3 $ (%4%)</span>")
                                    .arg(color)
                                    .arg(sign)
                                    .arg(change, 0, 'f', 2)
                                    .arg(percentChange, 0, 'f', 2));

        lastOilPrice = price;
        lastOilChange = percentChange;

        QDateTime now = QDateTime::currentDateTime();
        updateOilChart(price, now);
        saveDataToFile(0, price, now);

        updateMarketWarning();
        updateLastUpdateTime();
    }

    void processWeatherData(const QJsonObject &json) {
        if (json.contains("error")) {
            weatherTempLabel->setText("Ошибка получения данных");
            weatherStatusLabel->setText("Ошибка получения данных");
            return;
        }

        QJsonObject currentWeather = json["current_weather"].toObject();
        double temperature = currentWeather["temperature"].toDouble();
        int weathercode = currentWeather["weathercode"].toInt();
        double windspeed = currentWeather["windspeed"].toDouble();

        // Определение состояния погоды
        QString weatherCondition;
        QString weatherStatus;
        QString style;

        if (weathercode == 0) {
            weatherCondition = "Ясно";
            weatherStatus = "<b>Хорошая погода</b><br>Благоприятные условия для работы";
            style = "color: green;";
        } else if (weathercode == 1 || weathercode == 2 || weathercode == 3) {
            weatherCondition = "Переменная облачность";
            weatherStatus = "<b>Нормальная погода</b><br>Условия в пределах нормы";
            style = "color: green";
        } else if (weathercode == 45 || weathercode == 48) {
            weatherCondition = "Туман";
            weatherStatus = "<b>Плохая погода</b><br>Возможны задержки в работе";
            style = "color: red;";
        } else if (weathercode >= 51 && weathercode <= 67) {
            weatherCondition = "Дождь";
            weatherStatus = "<b>Плохая погода</b><br>Возможны задержки в работе";
            style = "color: red;";
        } else if (weathercode >= 71 && weathercode <= 77) {
            weatherCondition = "Снег";
            weatherStatus = "<b>Плохая погода</b><br>Возможны задержки в работе";
            style = "color: red;";
        } else if (weathercode >= 80 && weathercode <= 82) {
            weatherCondition = "Ливень";
            weatherStatus = "<b>Опасная погода</b><br>Высокая вероятность задержек";
            style = "color: darkred;";
        } else if (weathercode >= 95 && weathercode <= 99) {
            weatherCondition = "Гроза";
            weatherStatus = "<b>Опасная погода</b><br>Работы могут быть приостановлены";
            style = "color: darkred;";
        } else {
            weatherCondition = "Облачно";
            weatherStatus = "<b>Нормальная погода</b><br>Условия в пределах нормы";
            style = "color: green";
        }

        // Обновление UI
        weatherTempLabel->setText(QString("%1 °C").arg(temperature, 0, 'f', 1));
        weatherConditionLabel->setText(weatherCondition);
        weatherWindLabel->setText(QString("%1 км/ч").arg(windspeed, 0, 'f', 1));

        weatherStatusLabel->setText(weatherStatus);
        weatherStatusLabel->setStyleSheet(style);

        updateLastUpdateTime();
    }

    void updateMarketWarning() {
        if (lastOilChange == 0) return;

        QString warning;
        QString style;

        if (lastOilChange > 1.0) {
            warning = QString("<b>Рост цен на нефть!</b><br>"
                              "Рост нефти обычно положительно влияет на акции нефтегазовых компаний.");
            style = "color: green;";
        }
        else if (lastOilChange < -1.0) {
            warning = QString("<b>Падение цен на нефть!</b><br>"
                              "Падение цен на нефть может негативно влиять на доходы нефтегазовых компаний.");
            style = "color: red;";
        }
        else {
            warning = "Рынки демонстрируют стабильное поведение без значительных колебаний.";
        }

        warningLabel->setText(warning);
        warningLabel->setStyleSheet(style);
    }

    void manualUpdate() {
        fetchAllData();
        QMessageBox::information(this, "Обновление", "Данные успешно обновлены!");
    }

    void showAbout() {
        QMessageBox::about(this, "О программе",
                           "Монитор нефтегазовых акций (Газпром) v1.2\n\n"
                           "Отслеживание акций Газпрома - https://iss.moex.com\n\n"
                           "Отслеживание цен на нефть Brent - https://www.alphavantage.co \n\n"
                           "Отслеживание погоды - https://open-meteo.com \n\n"
                           "Карта - https://www.openstreetmap.org\n\n"
                           "Данные обновляются каждые 5 минут.");
    }

private:
    void updateLastUpdateTime() {
        lastUpdateTime = QDateTime::currentDateTime();
        updateLabel->setText("Последнее обновление: " + lastUpdateTime.toString("hh:mm:ss"));
    }

    void createMenu() {
        QMenuBar *menuBar = new QMenuBar(this);

        QMenu *fileMenu = menuBar->addMenu("Действия");
        QAction *updateAction = new QAction("Обновить данные", this);
        fileMenu->addAction(updateAction);
        fileMenu->addSeparator();

        QMenu *helpMenu = menuBar->addMenu("Справка");
        QAction *aboutAction = new QAction("О программе", this);
        helpMenu->addAction(aboutAction);

        connect(updateAction, &QAction::triggered, this, &StockViewer::manualUpdate);
        connect(aboutAction, &QAction::triggered, this, &StockViewer::showAbout);

        setMenuBar(menuBar);
    }

private:
    // Главная вкладка
    QLabel *warningLabel;
    QLabel *weatherStatusLabel;
    QLabel *gazpromLabel;
    QLabel *gazpromChangeLabel;
    QLabel *updateLabel;
    QChartView *gazpromChartView;
    QChart *gazpromChart;

    // Вкладка нефти
    QLabel *oilPriceLabel;
    QLabel *oilChangeLabel;
    QChartView *oilChartView;
    QChart *oilChart;

    // Вкладка погоды
    QWebEngineView *webView;
    QLineEdit *latitudeEdit;
    QLineEdit *longitudeEdit;
    QLabel *weatherTempLabel;
    QLabel *weatherConditionLabel;
    QLabel *weatherWindLabel;

    QNetworkAccessManager *networkManager;
    QTimer *updateTimer;
    QDateTime lastUpdateTime;

    // Данные для анализа
    double lastOilPrice = 0;
    double lastOilChange = 0;
    double lastGazpromPrice = 0;
    double lastGazpromChange = 0;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    StockViewer window;
    window.show();

    return app.exec();
}

#include "main.moc"
