/*char **str = split(keyin,' ');*/
/*static char **split(char *str,char target){
    int i,str_length = strlen(str),target_num=1;
    int p=0,ptr_p=0;
    char **result;
    for(i=0;i<str_length;i++){
        if(str[i]==target)target_num++;
    }
    result = (char**)malloc(sizeof(char)*target_num);
    
    for(i=0;i<=str_length;i++){
        if(str[i]==target||i==str_length){
            result[ptr_p] = &str[p];
            str[i]='\0';
            ptr_p++;p=i+1;continue;
        }
    }
    return result;
}*/