#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PUBLICINTERFACE_LIB)
#  define PUBLICINTERFACE_EXPORT Q_DECL_EXPORT
# else
#  define PUBLICINTERFACE_EXPORT Q_DECL_IMPORT
# endif
#else
# define PUBLICINTERFACE_EXPORT
#endif
