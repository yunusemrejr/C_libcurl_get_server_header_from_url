#include <stdio.h>
#include <stdbool.h>
#include <curl/curl.h>


 //below function hideHTML will help us for not getting the HTML body
static size_t hideHTML(char *data, size_t size_t_var_1, size_t size_t_var_2, void *userInput)
{

  (void)data;
  (void)userInput;
  return size_t_var_1 * size_t_var_2 ;
}







int function1(){
      CURL *curl_pointer;
 
  curl_pointer = curl_easy_init();

  if(curl_pointer) {

    CURLcode response;

    struct curl_header *header_info;

//target
    curl_easy_setopt(curl_pointer, CURLOPT_URL, "https://yunusemrevurgun.com");
 
 //redirection//
 curl_easy_setopt(curl_pointer, CURLOPT_FOLLOWLOCATION, 1);
 
     curl_easy_setopt(curl_pointer, CURLOPT_WRITEFUNCTION, hideHTML);
 

    /* Perform the request, res will get the return code */
    response = curl_easy_perform(curl_pointer);


    /* Check for errors */
    if(response != CURLE_OK)
      fprintf(stderr, "Curl failed: %s\n\n",
              curl_easy_strerror(response));
 
    if(CURLHE_OK == curl_easy_header(curl_pointer, "Content-Type", 0, CURLH_HEADER,-1, &header_info)){
     
      printf("Target\'s Content Type is: %s\n\n", header_info->value);
 
    printf("Complete Server Header:\n\n");
    
      struct curl_header *next_header; //pointer
      struct curl_header *previous = NULL; //pointer
      do {
        next_header = curl_easy_nextheader(curl_pointer, CURLH_HEADER, -1, previous); //"-1" means last request, 0 means first

        if(next_header){
          printf(" %s: %s (%u)\n", next_header -> name, next_header -> value, (int)next_header -> amount); //%n means unsigned int, which means ony + values
        previous = next_header;
        }

      } 
      
      while(next_header);
 
    }
     curl_easy_cleanup(curl_pointer); //freeing the memory
  }
  printf("%s\n\n");
  return 200;
}












int functionSimple(){

    printf("%s Successfully received the header detials, now repeating it again without checking the redirection: %s\n\n");
CURL *curl_pointer;
  curl_pointer = curl_easy_init();
  if(curl_pointer) {
    CURLcode response;
    struct curl_header *header_info;
    curl_easy_setopt(curl_pointer, CURLOPT_URL, "https://yunusemrevurgun.com");
     curl_easy_setopt(curl_pointer, CURLOPT_WRITEFUNCTION, hideHTML);
    response = curl_easy_perform(curl_pointer);
    if(response != CURLE_OK)
      fprintf(stderr, "Curl failed: %s\n\n",
              curl_easy_strerror(response));
    if(CURLHE_OK == curl_easy_header(curl_pointer, "Content-Type", 0, CURLH_HEADER,-1, &header_info)){
      printf("Target\'s Content Type is: %s\n", header_info->value , "%s \n");
    printf("Complete Server Header:\n");
      struct curl_header *next_header; //pointer
      struct curl_header *previous = NULL; //pointer
      do {
        next_header = curl_easy_nextheader(curl_pointer, CURLH_HEADER, -1, previous); //"-1" means last request, 0 means first
        if(next_header){
          printf(" %s: %s (%u)\n", next_header->name, next_header->value, (int)next_header->amount); //%n means unsigned int, which means ony + values
        previous = next_header;
        }
      } 
      while(next_header);
    }
     curl_easy_cleanup(curl_pointer); //freeing the memory
  }
  return 200;
}






int main(void)
{
    

    if(function1()==200){

 functionSimple();
    }
    
    else{
        printf("%serror @ function1");
    }
   
   printf("%s Successfully completed all duties of the program. ");
return 0;
}