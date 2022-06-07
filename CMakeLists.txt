cmake_minimum_required(VERSION 3.0.0)                      # cmake最低版本要求
project(StaffManager VERSION 0.1.0)                        # 工程名 工程版本
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")    # 可执行文件输出目录
AUX_SOURCE_DIRECTORY("${PROJECT_SOURCE_DIR}/src" DIR_SRCS) # 添加源代码文件夹, 自动扫描所有文件
add_executable(${PROJECT_NAME} ${DIR_SRCS})                # 输出可执行文件