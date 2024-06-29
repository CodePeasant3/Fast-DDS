# https://gitlab.kitware.com/cmake/community/-/wikis/doc/cpack/Configuration
# https://gitlab.kitware.com/cmake/community/-/wikis/doc/cpack/PackageGenerators

# 查找命令, 获取系统参数
find_program(LSB_RELEASE_EXEC lsb_release)
execute_process(COMMAND ${LSB_RELEASE_EXEC} -c -s
    OUTPUT_VARIABLE LSB_RELEASE_ID_SHORT
    OUTPUT_STRIP_TRAILING_WHITESPACE)

find_program(DPKG_EXEC dpkg)
execute_process(COMMAND ${DPKG_EXEC} --print-architecture
    OUTPUT_VARIABLE DPKG_ARCH
    OUTPUT_STRIP_TRAILING_WHITESPACE)

# 打包相关
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})

set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME}_${PROJECT_VERSION}_${DPKG_ARCH}_${LSB_RELEASE_ID_SHORT})
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_OUTPUT_FILE_PREFIX packages)

# debug symbol package(生成符号表包)
set(CPACK_DEBIAN_DEBUGINFO_PACKAGE OFF)

# Source package(生成源文件包)
set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_SOURCE_IGNORE_FILES "${PROJECT_BINARY_DIR};/.git/")


# 描述
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "TODO")

# 供应商信息
set(CPACK_PACKAGE_VENDOR Haoming)
set(CPACK_PACKAGE_CONTACT juhaoming@outlook.com)

# 版本相关
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

# 平台相关
set(CPACK_SYSTEM_NAME ${CMAKE_SYSTEM_NAME})
set(CPACK_PACKAGE_ARCHITECTURE ${DPKG_ARCH})
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${DPKG_ARCH})

# 依赖
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS OFF) # 若该标志为NO, 则将自动获取依赖, 若想完全手动设置则需要关闭
#set(CPACK_DEBIAN_PACKAGE_DEPENDS "TODO")
#set(CPACK_DEBIAN_PACKAGE_DEPENDS "ying (>= 1.0.4), protobuf-compiler (>= 3.0.0), libyaml-cpp-dev (>= 0.5.2)")

include(CPack)
