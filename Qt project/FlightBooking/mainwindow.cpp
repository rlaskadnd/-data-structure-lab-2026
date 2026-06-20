#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QLocale>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupFlightData();
    isFlightSelected = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupFlightData()
{
    flightDatabase.append({"LJ302", "진에어  ", "서울 -> 제주", 85000, "1시간 0분"});
    flightDatabase.append({"KE123", "대한항공", "서울 -> 제주", 120000, "1시간 5분"});
    flightDatabase.append({"OZ890", "아시아나", "서울 -> 도쿄", 450000, "2시간 20분"});
    flightDatabase.append({"TW701", "티웨이  ", "부산 -> 양양", 65000, "1시간 10분"});
    flightDatabase.append({"7C105", "제주항공", "제주 -> 부산", 70000, "0시간 50분"});
}

// [기능 1] 항공편 조회하기 버튼 클릭
void MainWindow::on_pushButton_clicked()
{
    QString departure = ui->lineEdit->text().trimmed();
    QString destination = ui->lineEdit_2->text().trimmed();

    if (departure.isEmpty() || destination.isEmpty()) {
        QMessageBox::warning(this, "경고", "출발지와 목적지를 모두 입력해주세요.");
        return;
    }

    ui->listWidget->clear();
    isFlightSelected = false;
    ui->label->setText("선택된 항공편이 없습니다.");

    QString searchRoute = departure + " -> " + destination;
    bool found = false;

    // 경고 해결: qAsConst를 사용하여 컨테이너 분리(detach) 현상 방지
    for (const Flight& f : qAsConst(flightDatabase)) {
        if (f.route == searchRoute) {
            // 경고 해결: 여러 개의 .arg() 대신 multi-arg 구조로 통합
            QString displayText = QString("  %1 (%2) \t %3 \t ₩%4 \t   %5")
                                      .arg(f.flightNo,
                                           f.airline,
                                           f.route,
                                           QLocale(QLocale::English).toString(f.price),
                                           f.duration);

            QListWidgetItem* item = new QListWidgetItem(displayText);
            item->setData(Qt::UserRole, f.flightNo);
            ui->listWidget->addItem(item);
            found = true;
        }
    }

    if (!found) {
        QMessageBox::information(this, "조회 결과", "해당 구간의 항공편이 존재하지 않습니다.\n(예시: 서울 / 제주 입력)");
    }
}

// [기능 2] 리스트 아이템 클릭
void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString flightNo = item->data(Qt::UserRole).toString();

    // 경고 해결: qAsConst 사용
    for (const Flight& f : qAsConst(flightDatabase)) {
        if (f.flightNo == flightNo) {
            selectedFlight = f;
            isFlightSelected = true;

            // 경고 해결: multi-arg 구조로 통합
            ui->label->setText(QString("선택됨: %1 (%2) | 요금: ₩%3")
                                   .arg(f.flightNo, f.route, QLocale(QLocale::English).toString(f.price)));
            break;
        }
    }
}

// [기능 3] 예매하기 버튼 클릭
void MainWindow::on_pushButton_2_clicked()
{
    if (!isFlightSelected) {
        QMessageBox::warning(this, "선택 필요", "조회된 목록에서 예매할 항공편을 먼저 클릭해 주세요.");
        return;
    }

    // 경고 해결: multi-arg 구조로 통합
    QString receipt = QString("🎉 예매가 성공적으로 완료되었습니다!\n\n"
                              "✈️ 항공편: %1 (%2)\n"
                              "📍 구간: %3\n"
                              "💵 요금: ₩%4\n"
                              "⏱️ 소요 시간: %5")
                          .arg(selectedFlight.flightNo,
                               selectedFlight.airline.trimmed(),
                               selectedFlight.route,
                               QLocale(QLocale::English).toString(selectedFlight.price),
                               selectedFlight.duration);

    QMessageBox::information(this, "예매 완료", receipt);
}
