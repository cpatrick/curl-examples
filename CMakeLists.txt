project( curl-examples )

cmake_minimum_required(VERSION 2.8)

find_package( CURL REQUIRED )

# First Example: HTTP HEAD
add_executable( CURLExample1 CURLExample1.cxx )
target_link_libraries( CURLExample1 ${CURL_LIBRARY} )

# Second Example: HTTP GET and save a file
add_executable( CURLExample2 CURLExample2.cxx )
target_link_libraries( CURLExample2 ${CURL_LIBRARY} )
