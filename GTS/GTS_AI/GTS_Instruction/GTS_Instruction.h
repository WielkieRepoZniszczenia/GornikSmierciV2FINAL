#ifndef GTS_INSTRUCTION_H
#define GTS_INSTRUCTION_H

namespace GTS
{
	class Instruction
	{
		public:
			Instruction();
			virtual ~Instruction();

			int set_parent(GTS::Instruction* parent);
			GTS::Instruction* get_parent();

			virtual int set_child(GTS::Instruction* child) = 0;

			virtual int process() = 0;

		protected:


		private:
			GTS::Instruction* m_parent;


	};
	#include "GTS_Instruction.cpp"
}
#endif // GTS_INSTRUCTION_H
