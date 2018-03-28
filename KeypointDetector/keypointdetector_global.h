#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(KEYPOINTDETECTOR_LIB)
#  define KEYPOINTDETECTOR_EXPORT Q_DECL_EXPORT
# else
#  define KEYPOINTDETECTOR_EXPORT Q_DECL_IMPORT
# endif
#else
# define KEYPOINTDETECTOR_EXPORT
#endif
