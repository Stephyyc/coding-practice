/* Task: complete the braces function which takes in one parameter (an array of n strings, values).
For each string in values, the function must determine if all the braces in the string are balanced.
Balanced, meaning there are {} [] and () are all balanced. The function must return an array of strings where the string at each index 
denotes whether or not the string at the original index in values was balanced or not. If yes, then must contain string YES. 
Otherwise, the return array must contain the string NO.
*/ 

/*
 * Complete the function below.
 */

/* I apologize in advance for the messy and inelegant code, but I do hope it works! */ 

vector < string > braces(vector < string > values) {
    
    /* Initalize the return vector - initially I wanted to use sets, but while debugging I got rid of them */
    vector<string> return_vector;
    
    int array_number;
    
    /* Iterate through the array of strings */
    for (int array_number = 0; array_number < values.size(); array_number++) {
        
        /* default: return_vector is full of "YES" */
        return_vector.push_back("YES");
        
        /* Create a stack to put the opening brackets into */
        stack<char> symbol_store;
        
        /* obtain each string and look at each character within the string 
        str_pos = string position */
        string current_string = values[array_number];
        for (int str_pos = 0; str_pos < current_string.length(); str_pos++) {
                        
            /* if the char is an opening brace, push it into the stack */
            if(current_string[str_pos] == '(' || current_string[str_pos] == '{' || current_string[str_pos] == '[') {
                symbol_store.push(current_string[str_pos]);
                cout << "opening brace" << endl;
            }
                        
            /* if the char is an ending brace, first check if the stack is empty - if it is, then braces are unbalanced */            
            else {  
                
                if(symbol_store.empty()) {
                    return_vector.pop_back();
                    return_vector.push_back("NO");
                }
                                    
                /* If the stack is not empty, pop the stack*/
                else {
                    
                    char temp = symbol_store.top();                    
                    symbol_store.pop();
                    
                    /* if the popped item couldn't be found in the opening brace set, stop */
                    if (temp != '(' && temp != '[' && temp != '{') {
                        return_vector.pop_back();
                        return_vector.push_back("NO");
                    }
                    
                    /* then check if the top of the stack is corresponding opening brace */
                    else if(current_string[str_pos] == ')') { 
                        if (temp != '(') {
                            return_vector.pop_back();
                            return_vector.push_back("NO");
                        }
                            
                    }
                    else if(current_string[str_pos] == '}') { 
                        if (temp != '{') {                            
                            return_vector.pop_back();
                            return_vector.push_back("NO");
                        }
                            
                    }
                    else if(current_string[str_pos] == ']') { 
                        if (temp != '[') {
                            return_vector.pop_back();
                            return_vector.push_back("NO");
                        }                    
                    }                                                         
            }                            
        }                   
    } // ending of string iteration
        
        /* if the stack is not empty when we finished going through the string, then there was an extra opening brace */
         if (!symbol_store.empty()) {
            return_vector.pop_back();
            return_vector.push_back("NO");
        }
    }       
    return return_vector;
}

/