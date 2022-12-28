#include "Component.h"

Component::Component( struct Property* prop,
                      QWidget* THIS,
                      QWidget* parent,
                      QString* src )
{
  this->prop   = prop;
  this->THIS   = THIS;
  this->parent = parent;
  this->src    = src;
  
  // Set size
  this->THIS->setFixedSize( (const QSize &)this->prop->_size );

  this->THIS->setMinimumSize( (const QSize &)this->prop->_minSize );
  this->THIS->setMaximumSize( (const QSize &)this->prop->_maxSize );
  
  // Set position
  this->THIS->move( (const QPoint &)this->prop->_position );
  
  // Set parent
  this->THIS->setParent( parent );

}
