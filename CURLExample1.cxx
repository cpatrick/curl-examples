/*=========================================================================
 *
 *  Copyright Patrick Reynolds
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include <curl/curl.h>
#include <iostream>

/** skeletion output callback function */
size_t output_function(char *bufptr, size_t size, size_t nitems, void *userp)
{
  return size*nitems;
}

/** Simple command-line application for initiating a head request on the first
 * argument to the application. */
int main( int argc, char** argv )
{
  if( argc != 2 )
    {
    std::cout << "Usage: " << argv[0] << " url" << std::endl;
    return -1;
    }

  CURL* tmpCurl;
  CURLcode res;
  tmpCurl = curl_easy_init();
  curl_easy_setopt(tmpCurl, CURLOPT_WRITEFUNCTION, output_function);
  curl_easy_setopt(tmpCurl, CURLOPT_SSL_VERIFYHOST, 1);
  curl_easy_setopt(tmpCurl, CURLOPT_SSL_VERIFYPEER, false);
  curl_easy_setopt(tmpCurl, CURLOPT_URL, argv[1]);
  curl_easy_setopt(tmpCurl, CURLOPT_VERBOSE, 1);
  curl_easy_setopt(tmpCurl, CURLOPT_NOPROGRESS, true );
  curl_easy_setopt(tmpCurl, CURLOPT_FOLLOWLOCATION, true);
  curl_easy_setopt(tmpCurl, CURLOPT_NOBODY, true);
  res = curl_easy_perform(tmpCurl);
  curl_easy_cleanup(tmpCurl);
  return 0;
}
