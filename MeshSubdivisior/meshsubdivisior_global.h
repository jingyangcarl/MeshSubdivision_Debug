#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MESHSUBDIVISIOR_LIB)
#  define MESHSUBDIVISIOR_EXPORT Q_DECL_EXPORT
# else
#  define MESHSUBDIVISIOR_EXPORT Q_DECL_IMPORT
# endif
#else
# define MESHSUBDIVISIOR_EXPORT
#endif
