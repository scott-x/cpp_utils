/*
* @Author: scottxiong
* @Date:   2019-11-01 14:37:34
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-11-01 14:37:34
c++ 的switch只支持enume和int类型
*/

#ifndef __TIME_H__
#define __TIME_H__

#include <unistd.h>
#include <ctime>
namespace micky {
	//delay second
	void Sleep(unsigned int second){
		sleep(second);
	}

    time_t GetTimestamp() {
    	return time(0);
    }
    //https://www.runoob.com/cplusplus/cpp-date-time.html

    /*
       types

       ""                         0  
       "yyyy-mm-dd hh:mm:ss":     1
       "yyyymmdd":                2
       "yyyy年mm月dd日":           3
       "yyyy-mm-dd":              4
       "yyyy/mm/dd":              5
       "mmdd":                    6
       "mm/dd":                   7
       "mm-dd":                   8
       "mm月dd日":                 9
       "hh:mm:ss" :               10
       "mm/dd":                   11
       "hh:mm" :                  12
       "hh时mm分":                13
       "hh时mm分ss秒":            14
       "yyyy":                   15
       "yyyy年":                 16
       "yyyymm":                 17
    */
	std::string GetTime(int types) {
		time_t now = time(0);
		tm *ltm = localtime(&now);
		int year = 1900 + ltm->tm_year;
		int month =  1 + ltm->tm_mon;
		int day = ltm->tm_mday;
		int hour = ltm->tm_hour;
		int min = ltm->tm_min;
		int sec = ltm->tm_sec;
        
        std::string s_year = std::to_string(year);
        std::string s_month = month<10?"0"+std::to_string(month):std::to_string(month);
        std::string s_day = day<10?"0"+std::to_string(day):std::to_string(day);
        std::string s_hour = hour<10?"0"+std::to_string(hour):std::to_string(hour);
        std::string s_min = min<10?"0"+std::to_string(min):std::to_string(min);
        std::string s_sec = sec<10?"0"+std::to_string(sec):std::to_string(sec);
        
        std::string res;
        switch(types){
        	case 0:
        	case 1:
        		res = s_year+"-"+s_month+"-"+s_day+" "+ s_hour+":"+s_min+":"+s_sec;
        		break;
        	case 2:
        		res = s_year+s_month+s_day;
        		break;
        	case 3:
        		res = 	s_year +"年"+ s_month+"月"+s_day+"日";
        		break;
        	case 4:
        	    res = s_year+"-"+s_month+"-"+s_day;
        	    break;
        	case 5:
        	    res = s_year+"/"+s_month+"/"+s_day;
        	    break;
        	case 6:
        		 res = s_month+s_day;
        		 break;
        	case 7:
        		 res = s_month+"/"+s_day;
        		 break;	
        	case 8:
        		 res = s_month+"-"+s_day;
        		 break;	
        	case 9 :	
        		 res =  s_month+"月"+s_day+"日";
        		 break;
        	case 10 :
        	 	 res = 	s_hour+":"+s_min+":"+s_sec;
        	 	 break;
        	case 11 :
        		 res =  s_hour+":"+s_min;
        		 break;
        	case 12:
        		 res = s_hour+"时"+s_min+"分";	 
        		 break;
        	case 13:
        		 res = s_hour+"时"+s_min+"分"+s_sec+"秒";
        		 break;
        	case 14:
        		 res = s_year;
        		 break;
            case 15:
            	 res = s_year +"年";
            	 break;
            case 16:
            	 res =  s_year+s_month;
            	 break;
            default:
            	 res = s_year+"-"+s_month+"-"+s_day+" "+ s_hour+":"+s_min+":"+s_sec;
            	 break; 

        }
        return res;

	}
} // micky

#endif