#include "mainwindow.h"
#include "Component.h"

void MainWindow::__init__( std::vector<Component*> *compons )
{
  compons->push_back( this->window );
  compons->push_back( this->codeArea );
  compons->push_back( this->william );
}

MainWindow::MainWindow( QWidget *parent ) {}

MainWindow::MainWindow( Component *window,
                        std::vector<Component *>compons,
                        QWidget *parent ) noexcept(true)
{
  for ( Component *it : compons )
    {
      property_check( it->prop );
      // Set parent(Component)
      it->THIS->setParent( parent );
      // Adjustions(Component)
      it->THIS->setFixedSize( (const QSize &)it->prop->_size );
      // Set status
      it->THIS->setEnabled( it->prop->_disabled );
    }
  
  // Resize window
  window->THIS->setFixedSize( (const QSize &)window->prop->_size );
}

MainWindow::~MainWindow() {}
