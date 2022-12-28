#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>

typedef struct Property
{
  const QSize*  _size;
  const QPoint* _position;
  const bool    _disabled;
  const QSize*  _minSize;
  const QSize*  _maxSize;
} Property;

const static QSize* DEFAULT = new QSize( -1, -1 );
const static QSize* DEFAULT_MINIMIUM_SIZE = new QSize( 0, 0 );
const static QSize* DEFAULT_MAXIMIUM_SIZE = new QSize( 65535, 65535 );

static struct Property DEFAULT_WINDOW_PROPERTY =
{
  new QSize( 880, 500 ),
  new QPoint( 0, 0 ),
  false,
  DEFAULT,
  DEFAULT
};

static struct Property DEFAULT_CODEAREA_PROPERTY =
{
  new QSize( 816, DEFAULT_WINDOW_PROPERTY._size->height() ),
  new QPoint( 0, 0 ),
  false,
  DEFAULT,
  DEFAULT
};

static struct Property DEFAULT_WILLIAM_PROPERTY =
{
  new QSize( 64, 64 ),
  new QPoint( DEFAULT_CODEAREA_PROPERTY._size->width(), 0 ),
  false,
  DEFAULT,
  DEFAULT
};

static inline void property_check( Property *target )
{
  if ( target->_minSize == DEFAULT )
    {
      target->_minSize = target->_size;
    }
  
  if ( target->_maxSize == DEFAULT )
    {
      target->_maxSize = target->_size;
    }
}

class Component
{
public:
  // Constructors
  Component( struct Property* prop,
             QWidget* THIS,
             QWidget* parent = nullptr,
             QString* src = nullptr );
  
  // Fields
  struct Property *prop;
  QWidget *THIS;
  QWidget *parent;
  QString *src;
};

#endif // COMPONENT_H
