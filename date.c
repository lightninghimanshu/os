#include <stdio.h>
#include <time.h>
#include <string.h>
char * days[]={
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Sat",
};

char * months[]={
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"
};

int dateR(){
    time_t rawtime = time(NULL);
    struct tm * timeinfo = localtime(&rawtime);
    char * day= days[timeinfo->tm_wday];
    int date = timeinfo->tm_mday;
    char * month = months[timeinfo->tm_mon];
    int year = timeinfo->tm_year;
    year+=1900;
    int hour = timeinfo->tm_hour;
    int min = timeinfo->tm_min;
    int sec = timeinfo->tm_sec;
    printf("%s, %02d %s %d %02d:%02d:%02d",day,date,month,year,hour,min,sec);
    int tmzone=timeinfo->tm_gmtoff;
    int tmzonehr=timeinfo->tm_gmtoff/60/60;
    int tmzonemin=(tmzone-tmzonehr*60*60)/60;
    printf(" +%02d",tmzonehr);
    printf("%02d\n",tmzonemin);
}

int dateu(){
    time_t rawtime = time(NULL);
    struct tm * timeinfo = gmtime(&rawtime);
    char * day= days[timeinfo->tm_wday];
    int date = timeinfo->tm_mday;
    char * month = months[timeinfo->tm_mon];
    int year = timeinfo->tm_year;
    year+=1900;
    int hour = timeinfo->tm_hour;
    int min = timeinfo->tm_min;
    int sec = timeinfo->tm_sec;
    int tmzone=timeinfo->tm_gmtoff;
    int tmzonehr=timeinfo->tm_gmtoff/60/60;
    int tmzonemin=(tmzone-tmzonehr*60*60)/60;
    printf("%s %s %02d %02d:%02d:%02d %s %d\n",day,month,date,hour,min,sec,"UTC",year);
}

int date(){
    time_t rawtime = time(NULL);
    struct tm * timeinfo = localtime(&rawtime);
    char * day= days[timeinfo->tm_wday];
    int date = timeinfo->tm_mday;
    char * month = months[timeinfo->tm_mon];
    int year = timeinfo->tm_year;
    year+=1900;
    int hour = timeinfo->tm_hour;
    int min = timeinfo->tm_min;
    int sec = timeinfo->tm_sec;
    int tmzone=timeinfo->tm_gmtoff;
    int tmzonehr=timeinfo->tm_gmtoff/60/60;
    int tmzonemin=(tmzone-tmzonehr*60*60)/60;
    printf("%s %s %02d %02d:%02d:%02d %s %d\n",day,month,date,hour,min,sec,timeinfo->tm_zone,year);
}

int main(int argc, char *argv[]){
    char * token = argv[1];
    if (argc==1){
        date();
    }
    else if (strcmp(argv[1],"-R")==0){
        dateR();
    }
    else if (strcmp(argv[1],"-u")==0){
        dateu();
    }
    else if (argv[1][0]=='-'){
		printf("Wrong Flag\n");
	} 
    else{
        printf("Invalid\n");
    }
    return 0;
}