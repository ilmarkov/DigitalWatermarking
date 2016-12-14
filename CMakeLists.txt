cmake_minimum_required(VERSION 3.6)
project(WatermarkEngine)




# To use PKG_CHECK_MODULES to find some optional packages
find_package(PkgConfig)

#    Tell CMake where to leave executables
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

#Path of CImg.h file relative to this file image_path_embed
set(CIMG_H_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories( ${PROJECT_SOURCE_DIR} )
include_directories( ${CIMG_H_PATH} )



# ### CIMG related stuff
# Flags to enable fast image display, using the XSHM library.
SET(CIMG_XSHM_CCFLAGS  -Dcimg_use_xshm)

# Flags to enable screen mode switching, using the XRandr library.
SET(CIMG_XRANDR_CCFLAGS  -Dcimg_use_xrandr)

# Flags to enable native support for JPEG image files, using the JPEG library.
# ( http://www.ijg.org/ )
SET(CIMG_JPEG_CCFLAGS  -Dcimg_use_jpeg)

# Flags to enable native support for TIFF image files, using the TIFF library.
# ( http://www.libtiff.org/ )
SET(CIMG_TIFF_CCFLAGS  -Dcimg_use_tiff)

# Flags to enable native support for PNG image files, using the PNG library.
# ( http://www.libpng.org/ )
SET(CIMG_PNG_CCFLAGS  -Dcimg_use_png)


# Flags to enable native support of most classical image file formats, using the Magick++ library.
# ( http://www.imagemagick.org/Magick++/ )
SET(CIMG_MAGICK_CCFLAGS -Dcimg_use_magick)

# Flags to enable faster Discrete Fourier Transform computation, using the FFTW3 library
# ( http://www.fftw.org/ )
SET(CIMG_FFTW3_CCFLAGS  -Dcimg_use_fftw3)


# ### Search Additional Libraries ##########
FIND_PACKAGE(JPEG)
FIND_PACKAGE(PNG)

PKG_CHECK_MODULES(FFTW3 fftw3)
PKG_CHECK_MODULES(OPENEXR OpenEXR)
PKG_CHECK_MODULES(MAGICK Magick++)

# PKG_CHECK_MODULES(LIBAVCODEC libavcodec)
# PKG_CHECK_MODULES(LIBAVFORMAT libavformat)
# PKG_CHECK_MODULES(LIBSWSCALE libswscale)
# PKG_CHECK_MODULES(LIBAVUTIL libavutil)

if(NOT WIN32)
    FIND_PACKAGE(X11)
    FIND_PACKAGE(Threads REQUIRED)
endif()

# #### End of additional libraries search ##########


if(JPEG_FOUND)
    get_filename_component(JPEG_LIB_DIRS ${JPEG_LIBRARIES} PATH)
    SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_JPEG_CCFLAGS}")
    link_directories(${JPEG_LIB_DIRS})
    include_directories(${JPEG_INCLUDE_DIR})
    SET(SYSTEM_LIBS ${SYSTEM_LIBS} ${JPEG_LIBRARIES})
endif()



if(MAGICK_FOUND)
    SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_MAGICK_CCFLAGS}")
    link_directories( ${MAGICK_LIBRARY_DIRS} )
    include_directories( ${MAGICK_INCLUDE_DIRS} )
    SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${MAGICK_LIBRARIES} )
endif()



if(NOT APPLE)
    if(NOT WIN32)
        if(X11_FOUND)
            SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_XSHM_CCFLAGS} ${CIMG_XRANDR_CCFLAGS}")
            SET(SYSTEM_LIBS ${SYSTEM_LIBS} Xext Xrandr)
        endif()
    endif(NOT WIN32)
endif(NOT APPLE)

if(X11_FOUND)
    link_directories(${X11_LIB_DIRS})
    include_directories(${X11_INCLUDE_DIR})
    SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${X11_LIBRARIES} )
endif()

if (NOT WIN32)
    SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${CMAKE_THREAD_LIBS_INIT} )
endif()


# -------- QT Build -----------
set(QT_PATH ${PROJECT_SOURCE_DIR}/Interface)

find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


qt5_wrap_ui(tst_form_hdr Interface/makewm.ui Interface/validation.ui Interface/menu.ui Interface/creation.ui)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CIMG_CFLAGS} -std=c++11")

file(GLOB xml_lib "lib/xml_parser/*.cpp" "lib/xml_parser/*h")
file(GLOB qt_rel "Interface/*.h")

set(SOURCE_FILES main.cpp utils/ImageTree.h utils/MyImage.h utils/DWTUtil.cpp utils/DWTUtil.h utils/DWT.h model/Watermark_Plugin.h
        model/DWTDugad.h model/Signature.h model/DWTDugad.cpp
        utils/ProjectException.h utils/ParserUtil.h ${xml_lib} model/Model.h Controllers/SimpleController.h Controllers/Controller.h Views/View.h
        Interface/menu.cpp Interface/creation.cpp Interface/validation.cpp Interface/makewm.cpp
        ${qt_rel}
        Controllers/QTController.h Views/QTView.h)

add_executable(WatermarkEngine ${SOURCE_FILES} ${tst_form_hdr})
target_link_libraries(WatermarkEngine ${SYSTEM_LIBS} Qt5::Widgets)


qt5_use_modules(WatermarkEngine Core Widgets Gui )

#SET(CMAKE_VERBOSE_MAKEFILE 1)