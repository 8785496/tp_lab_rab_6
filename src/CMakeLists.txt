set(SOURCE_FILES GraphBase.cpp App.cpp GraphWrite.cpp GraphFind.cpp GraphDelete.cpp GraphException.cpp GraphException.h ArgumentException.cpp ArgumentException.h)

add_library(src STATIC ${SOURCE_FILES})