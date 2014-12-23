#ifndef GTS_BUTTON_H
#define GTS_BUTTON_H


namespace GTS
{
	class Button
	{
		public:
			Button();
			virtual ~Button();

			/** @@ CONSTANT EVENT CHECK @@
				* should be used after all buttons are updated !!
				* use this, for example:
							* if you need to render something depend on button state
							* if something is going on every loop
							* if you want to move actor depend on key type
				*/
				bool const_check();

			/** @@ ONE TIME EVENT CHECK @@
				* should be used after all buttons are updated !!
				* use this protected check method if:
							* you want to load something only once per button state change(new objects in editor list)
							* you want to move something about constant value, once per button "click"
				  			* ...basically, you want to do something ONCE, if button state changed
				*/
				bool single_check();



			/** @@ LINK BREAK @@
				* this is flag that is set if none of the linked buttons is pressed

				* example:
					int myLink = GTS::Button::LINK_BREAK;

					(...)

					if(myLink == GTS::Button::LINK_BREAK)
					{
						//action
					}
				*/
				static const int LINK_BREAK;



///@@@@@@@@@@@@ user settings

			/** @@ SETTING COLLISION @@
				* this sets the button filed of action for events system
				*/
				void set_box(int x, int y, unsigned int w, unsigned int h);

			/** @@ SETTING ACTIVATION @@
				* this will activate/deactivate "inactive button state" and optionally render button with inactive texture
				* if button is inactive, its events are not checked
				*/
				void set_active(bool flag);

			/** @@ SETTING LINK SYSTEM @@
				* buttons can be grouped together in systems
				* if one is pressed, others will be unpressed
				* you must control link variable outside this class
				* buttonID is its link id (to distinguish them from another)
				* buttonID can't be set to LINK_BREAK value (look at the top of .cpp file, it should have value -1)
				  it will return -1 on bad initialization
				*/
				int set_link(int &link, int buttonID);

			/** @@ SETTING BOUNCE PARAMETERS @@
				* bounce time is set to 0 by default
				* if bounce is set to 0 button will act like switch, if you press it, it will be set as pressed,
				  if you press it again, it will change to unpressed
				* after given time button will change to unpressed state
				*/
				void set_bounce(long bounceTime = 500);

			/** @@ SETTING GLOBAL MOUSE OVER @@
				* use this if your application need to now if mouse is over any of the GTS::Button that has this flag set
				*/
				void set_globalMouseOver(bool &globalMouseOver);

			/** @@ SETTING THE TEXTURES @@
				* only unpressed texture is mandatory
				* if some button state has no texture (for exp. inactive state) it will use unpressed texture
				*/
				int set_unpressedTexture(GTS::Texture* texture);
				int set_pressedTexture(GTS::Texture* texture);
				int set_highlightedTexture(GTS::Texture* texture);
				int set_inactiveTexture(GTS::Texture* texture);

///@@@@@@@@@@@@

			/** @@ EVENTS @@
				* it will return -1 if mBox.w or mBox.h is equal 0
				*/
				int events(SDL_Event &event);

			/** @@ WHY AND HOW TO UPDATE @@
				* it should be used if button is flagged(it can be unpressed only after all buttons events are checked)
				* if button has some kind of visual mods (like fade away effect) also should be updated
				* if button has bounce time != 0

				* you should put this method in state->logic() section (that way you are 100% sure that all buttons events were checked)

				*/
				void update(long currentTime);

			/** @@ BUTTON SOUND EFFECTS @@
				* not available yet
				*/
				int sounds();

			/** @@ RENDER @@
				* if you want to render in specific position, use set_box() first
				* button will be displayed in window specified by currently used texture
				*/
				int render();

		protected:
			bool bActive;

			bool bPressed;
			bool bChecked;

			void set_press(bool flag);

			long mBounceTime;
			long mBounceStartTime;

			bool bMouseOver;
			bool* bGlobalMouseOver;

			/// BOX
			SDL_Rect mBox;

			/// LINK SYSTEM
			bool bLinked;
			int* mLink;
			int mLinkID;

			/// TEXTURES
			GTS::Texture* mUnpressedTexture;
			GTS::Texture* mPressedTexture;
			GTS::Texture* mHighlightedTexture;
			GTS::Texture* mInactiveTexture;

		private:


	};

	#include "GTS_Button.cpp"
}

#endif // BUTTON_H
