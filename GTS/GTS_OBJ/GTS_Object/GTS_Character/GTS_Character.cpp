

/// CTOR / DTOR / COPY CTOR
Character::Character()
{
	m_description = NULL;
	m_abilities = NULL;
	m_items = NULL;
	m_features = NULL;
	m_state = NULL;
	m_animations = NULL;
}
Character::~Character()
{
	if(m_description != NULL)
		delete m_description;

	if(m_abilities != NULL)
		delete m_abilities;

	if(m_items != NULL)
		delete m_items;

	if(m_features != NULL)
		delete m_features;

	if(m_state != NULL)
		delete m_state;

	if(m_animations != NULL)
		delete m_animations;
}
Character::Character(const Character& other)
{
	*this = other;
	m_description = new GTS::CharacterDescription(*other.m_description);
	m_abilities = new GTS::CharacterAbilities(*other.m_abilities);
	m_items = new GTS::CharacterItems(*other.m_items);
	m_features = new GTS::CharacterFeatures(*other.m_features);
	m_state = new GTS::CharacterState(*other.m_state);
	m_animations = new GTS::CharacterAnimations(*other.m_animations);
}
///



/// CHARACTER INTERFACE
int Character::set_description(const GTS::CharacterDescription& description)
{
	if(m_description != NULL)
		delete m_description;

	m_description = new GTS::CharacterDescription(description);

	return 0;
}
int Character::set_abilities(const GTS::CharacterAbilities& abilities)
{
	if(m_abilities != NULL)
		delete m_abilities;

	m_abilities = new GTS::CharacterAbilities(abilities);

	return 0;
}
int Character::set_items(const GTS::CharacterItems& items)
{
	if(m_items != NULL)
		delete m_items;

	m_items = new GTS::CharacterItems(items);

	return 0;
}
int Character::set_features(const GTS::CharacterFeatures& features)
{
	if(m_features != NULL)
		delete m_features;

	m_features = new GTS::CharacterFeatures(features);

	return 0;
}
int Character::set_state(const GTS::CharacterState& state)
{
	if(m_state != NULL)
		delete m_state;

	m_state = new GTS::CharacterState(state);

	return 0;
}
int Character::set_animations(const GTS::CharacterAnimations& animations)
{
	if(m_animations != NULL)
		delete m_animations;

	m_animations = new GTS::CharacterAnimations(animations);

	return 0;
}
///



/// save/load this object
int Character::save(std::ofstream* fout)
{
	return 0;
}
int Character::load(std::ifstream* fin)
{
	return 0;
}
///
