/*
* @Author: scottxiong
* @Date:   2019-12-02 09:23:36
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-12-02 09:43:41
*/
namespace micky {
	class Server
	{
	public:
		Server();
		~Server();
	public:
		void serve(void (*run)());
	};	
} // micky
