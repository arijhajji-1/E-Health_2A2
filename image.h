#ifndef IMAGE_H
#define IMAGE_H

#include <QDialog>
#include<QGraphicsScene>
namespace Ui {
class image;
}

class image : public QDialog
{
    Q_OBJECT

public:
    explicit image(QWidget *parent = nullptr);
    ~image();
    void setchemin(QString);
private slots:
    void on_actionZoomInOut_triggered();




    void on_horizontalSlider_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_actionRotate_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::image *ui;
    //per visualizzare una immagine
    QGraphicsScene *scena; //l`intero mondo osservabile

    QGraphicsPixmapItem *immagine_gi;

    bool right_down = false; //per sapere se tasto destro premuto
    bool left_down = false; //per sapere se tasto sinistro premuto
    bool ctrl_down = false; //per sapere se CTRL premuto

    int inizio_pan_x = 0; //per pan con mouse
    int inizio_pan_y = 0; //per pan con mouse

    int debug_counter = 0;
   // QMediaPlayer *click;
protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void keyPressEvent(QKeyEvent *k);
    void wheelEvent(QWheelEvent *event);
    void keyReleaseEvent(QKeyEvent *k);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // IMAGE_H
