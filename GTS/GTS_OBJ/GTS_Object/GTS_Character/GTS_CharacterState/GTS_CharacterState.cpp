

/// CTOR / DTOR / COPY CTOR / AOP
CharacterState::CharacterState()
{
	//ctor
}
CharacterState::~CharacterState()
{
	//dtor
}
CharacterState::CharacterState(const CharacterState& other)
{
	//copy ctor
}
CharacterState& CharacterState::operator=(const CharacterState& rhs)
{
	if (this == &rhs) return *this; // handle self assignment
	//assignment operator
	return *this;
}
