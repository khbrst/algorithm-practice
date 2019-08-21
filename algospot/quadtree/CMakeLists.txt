project(quadtree)

add_executable(${PROJECT_NAME} src/solution.cc)
add_custom_target(run-${PROJECT_NAME}
    COMMAND ${PROJECT_NAME} < input.txt
)
