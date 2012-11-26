/*
   Copyright (C) 2012  Statoil ASA, Norway. 
    
   The file 'append_test.c' is part of ERT - Ensemble based Reservoir Tool. 
    
   ERT is free software: you can redistribute it and/or modify 
   it under the terms of the GNU General Public License as published by 
   the Free Software Foundation, either version 3 of the License, or 
   (at your option) any later version. 
    
   ERT is distributed in the hope that it will be useful, but WITHOUT ANY 
   WARRANTY; without even the implied warranty of MERCHANTABILITY or 
   FITNESS FOR A PARTICULAR PURPOSE.   
    
   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html> 
   for more details. 
*/
#include <stdlib.h>
#include <stdbool.h>

#include <config.h>



int main(int argc , char ** argv) {
  const char * config_file = argv[1];
  config_type * config = config_alloc();
  
  config_schema_item_type * item = config_add_schema_item(config , "APPEND" , false , true );
  
  bool OK = config_parse(config , config_file , "--" , NULL , NULL , false , true );
  
  if (OK) {
    if (config_get_occcurences( config , "APPEND" ) == 1) {
      const char * value = config_get_value( config , "APPEND");
      
      if (strcmp( value , "VALUE3") == 0)
        exit(0);
    }
    else
      exit(1);
  } else
    exit(1);
  
}
