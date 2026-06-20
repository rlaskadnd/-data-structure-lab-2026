#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// 항공편 데이터 구조체 (항공편명, 항공사, 구간, 요금, 소요시간)
struct Flight {
    QString flightNo;
    QString airline;
    QString route;     // 예: "서울 -> 제주"
    int price;         // 요금
    QString duration;  // 소요 시간
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 1. [항공편 조회하기] 버튼 클릭 함수
    void on_pushButton_clicked();

    // 2. 리스트에서 특정 항공편을 마우스로 클릭했을 때 함수
    void on_listWidget_itemClicked(QListWidgetItem *item);

    // 3. [예매하기] 버튼 클릭 함수
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Flight> flightDatabase; // 고정 항공편 데이터 배열
    Flight selectedFlight;          // 사용자가 현재 선택한 항공편 정보
    bool isFlightSelected = false;  // 항공편 선택 여부 플래그

    void setupFlightData();         // 고정 데이터 입력 함수
};
#endif // MAINWINDOW_H