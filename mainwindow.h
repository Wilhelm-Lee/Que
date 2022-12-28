#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QImage>
#include <vector>

#include "Component.h"

extern inline void property_check( Property *target );

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
private:
  std::vector<Component*> *compons;
  
  void __init__( std::vector<Component*> *compons );
  
public:
  Component *window;
  Component *codeArea;
  Component *william;
  
  MainWindow( QWidget *parent = nullptr );
  MainWindow( Component *window,
              std::vector<Component *>compons,
              QWidget *parent = nullptr )
      __THROW __nonnull((2));
  ~MainWindow();
};
#endif // MAINWINDOW_H
