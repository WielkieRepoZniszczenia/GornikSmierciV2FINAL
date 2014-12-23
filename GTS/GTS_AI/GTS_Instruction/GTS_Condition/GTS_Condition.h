#ifndef GTS_CONDITION_H
#define GTS_CONDITION_H


namespace GTS
{
	enum COND_VARIANT
	{
		COND_EQUAL = 0,
		COND_DIFFERENT
	};

	template<typename T>
	class Condition
	{
		public:
			Condition(T& conditionArgument, COND_VARIANT variant, T& model)
			{
				m_variant = variant;
				m_condArg = &conditionArgument;
				m_model = model;
			}
			~Condition(){};

			bool check()
			{
				if(m_condArg != NULL)
				{
					if(m_variant == COND_EQUAL)
					{
						if(*m_condArg == m_model)
							return true;
					}
					else//m_variant == COND_DIFFERENT
					{
						if(*m_condArg != m_model)
							return true;
					}
				}

				return false;
			}

			bool operator==(bool mod)
			{
				return this->check() == mod;
			}

		protected:
		private:
			COND_VARIANT m_variant;
			T* m_condArg;
			T m_model;
	};
	#include "GTS_Condition.cpp"

}

#endif // GTS_CONDITION_H
