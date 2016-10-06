
#ifndef AFX_DLL_H
#define AFX_DLL_H

#ifdef AFX_BUILT_AS_STATIC
#  define AFX_DLL
#  define AUDIOFX_NO_EXPORT
#else
#  ifndef AFX_DLL
#    ifdef afx_EXPORTS
        /* We are building this library */
#      define AFX_DLL __declspec(dllexport)
#    else
        /* We are using this library */
#      define AFX_DLL __declspec(dllimport)
#    endif
#  endif

#  ifndef AUDIOFX_NO_EXPORT
#    define AUDIOFX_NO_EXPORT 
#  endif
#endif

#ifndef AUDIOFX_DEPRECATED
#  define AUDIOFX_DEPRECATED __declspec(deprecated)
#endif

#ifndef AUDIOFX_DEPRECATED_EXPORT
#  define AUDIOFX_DEPRECATED_EXPORT AFX_DLL AUDIOFX_DEPRECATED
#endif

#ifndef AUDIOFX_DEPRECATED_NO_EXPORT
#  define AUDIOFX_DEPRECATED_NO_EXPORT AUDIOFX_NO_EXPORT AUDIOFX_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef AUDIOFX_NO_DEPRECATED
#    define AUDIOFX_NO_DEPRECATED
#  endif
#endif

#endif
