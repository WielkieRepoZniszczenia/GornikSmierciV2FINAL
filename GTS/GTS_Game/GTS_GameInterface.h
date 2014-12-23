#ifndef GTS_GAMEINTERFACE_H
#define GTS_GAMEINTERFACE_H

namespace GTS
{
	class GameInterface
	{
		public:
			GameInterface();
			virtual ~GameInterface();

			virtual GTS::State* get_firstState() = 0;


			virtual int set() = 0;
			virtual int set_map() = 0;

			virtual int save(std::ofstream* fout) = 0;
			virtual int load(std::ifstream* fin) = 0;

		protected:
		private:
	};

	#include "GTS_GameInterface.cpp"

}

#endif // GTS_GAMEINTERFACE_H
