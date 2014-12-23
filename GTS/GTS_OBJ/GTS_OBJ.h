#ifndef GTS_OBJ_H
#define GTS_OBJ_H


namespace GTS
{
	/** @brief
		 this is Object interface

	*/
	class OBJ
	{
		public:
			OBJ();
			virtual ~OBJ();

			/// save/load this object
			virtual int save(std::ofstream* fout) = 0;
			virtual int load(std::ifstream* fin) = 0;
			///

		protected:

		private:

	};

	#include "GTS_OBJ/GTS_OBJ.cpp"

}

#endif // GTS_OBJECT_H
