project( curl-examples )

cmake_minimum_required(VERSION 2.8)

find_package( CURL REQUIRED )

add_executable( CURLExample1 CURLExample1.cxx )
target_link_libraries( CURLExample1 ${CURL_LIBRARY} )