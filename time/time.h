/*
* @Author: scottxiong
* @Date:   2019-11-01 14:37:34
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-11-01 14:37:34
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
	std::string GetTime(std::string types) {
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
        	case "":
        	case "yyyy-mm-dd hh:mm:ss":
        		res = s_year+"-"+s_month+"-"+s_day+" "+ s_hour+":"+s_min+":"+s_sec;
        		break;
        	case "yyyymmdd":
        		res = s_year+s_month+s_day;
        		break;
        	case "yyyy年mm月dd日":
        		res = 	s_year +"年"+ s_month+"月"+s_day+"日";
        		break;
        	case "yyyy-mm-dd":
        	    res = s_year+"-"+s_month+"-"+s_day;
        	    break;
        	case "yyyy/mm/dd":
        	    res = s_year+"/"+s_month+"/"+s_day;
        	    break;
        	case "mmdd":
        		 res = s_month+s_day;
        		 break;
        	case "mm/dd":
        		 res = s_month+"/"+s_day;
        		 break;	
        	case "mm-dd":
        		 res = s_month+"-"+s_day;
        		 break;	
        	case "mm月dd日" :	
        		 res =  s_month+"月"+s_day+"日";
        		 break;
        	case "hh:mm:ss" :
        	 	 res = 	s_hour+":"+s_min+":"+s_sec;
        	 	 break;
        	case "hh:mm" :
        		 res =  s_hour+":"+s_min;
        		 break;
        	case "hh时mm分":
        		 res = s_hour+"时"+s_min+"分";	 
        		 break;
        	case "hh时mm分ss秒":
        		 res = s_hour+"时"+s_min+"分"+s_sec+"秒";
        		 break;
        	case "yyyy":
        		 res = s_year;
        		 break;
            case "yyyy年":
            	 res = s_year +"年";
            	 break;
            case "yyyymm":
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