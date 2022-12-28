#include <QApplication>
#include <QWidget>
#include <QPicture>

#include "Component.h"
#include "mainwindow.h"
#include "qtextedit.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  /* Code below */
  
  // codeArea
  QTextEdit *codeArea = new QTextEdit( "Lorem Ipsum", &w );
  QPicture  *william  = new QPicture();
  
  Component *compon_codeArea = new Component( &DEFAULT_CODEAREA_PROPERTY,
                                              codeArea );
  
  Component *compon_william = new Component( &DEFAULT_WILLIAM_PROPERTY,
                                             (QWidget *)william );
  
  // Free up(inner to outter)
  delete( compon_william );
  delete( compon_codeArea );
  delete(william);
  delete(codeArea);
  
  /* Code above */
  w.show();
  return a.exec();
}
