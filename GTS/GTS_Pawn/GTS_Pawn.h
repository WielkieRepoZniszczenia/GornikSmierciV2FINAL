#ifndef GTS_PAWN_H
#define GTS_PAWN_H

#include <vector>
#include <list>
#include <cmath>


namespace GTS
{
	class PawnFrame
	{
		public:
			PawnFrame()
			{
				texture = NULL;
				timeGap = 0;
			}
			PawnFrame(GTS::Vec2D<int> _offset, GTS::TexTrans _texTrans, long _timeGap = 0, GTS::Texture* _texture = NULL)
			{
				offset = _offset;
				trans = _texTrans;
				texture = _texture;
				timeGap = _timeGap;
			}
			GTS::Vec2D<int> offset; // offset from parent or rendering point
			GTS::TexTrans trans; // change texture: size, angle, etc.
			GTS::Texture* texture; // pawn texture pointer

			long timeGap;

		protected:
		private:
	};
}

namespace GTS
{
	/** @brief
		 * this class is visual representation of any object, character, item, etc. in game, and
		   should be used for pre-rendering sorting

		 * you can set pawn with default frame and rendering order
		 	e.g: Pawn pawn(GTS::PawnFrame(offset, texTrans, &texture, timeGap), GTS::Pawn::TOP);

		 * to animate pawn just add different pawn frames
		 * pawns are animated with loop mode by default, but you can turn it off
		 * during animation process pawn creates its approximated copy(and deletes it after rendering)
		   so there is no need to copy pawn structures to render different objects
		 * to render different texture just change PawnFrame.texture(it's a pointer) you need by calling get_frame(ID) // don't delete it !!!
		 * offset is a vector from rendering position, or from parent pawn(if you render parent)
		 * TexTrans is a class which holds texture transformations (angle, scale, flip rendering, clip rendering)
	*/
	class Pawn
	{
		public:
			enum RENDER_ORDER{
				TOP = 0,
				BOTTOM
			};
			Pawn();
			Pawn(PawnFrame& defaultFrame, RENDER_ORDER order, bool scaleOffset);
			~Pawn();


			/// PAWN SETTINGS
			void set_renderOrder(RENDER_ORDER order);
			int get_renderOrder();

			void set_offsetScaling(bool scale);
			bool get_offsetScaling();

			int add_child(Pawn* child);
			std::list<Pawn*> get_children();
			///

			/// ANIMATION SETTINGS
			int add_frame(GTS::PawnFrame frame);
			GTS::PawnFrame* get_frame(unsigned int id);
			///

			/// Pawn animation time
			long get_timeLine();



			/** @@ RENDER @@
				* texture is rendered based on transformation interpolation between current and next frame
				* if next frame is NULL(and time difference is grater than gap time), texture is rendered based on last frame
				* pawn transformation depend on its parent transformation, and it propagates to last child of current pawn
				*/
				int render(GTS::Vec2D<int> position, GTS::TexTrans trans, long timeFromStart);

		protected:
			int renderB(GTS::PawnFrame* appFrame, GTS::Vec2D<int> dPos, GTS::TexTrans& dTrans, long timeFromStart);

			PawnFrame* approx(PawnFrame* current, PawnFrame* next, GTS::Vec2D<int>& dOff, GTS::TexTrans& dTexTrans, long dt);

			int get_currentID(long& timeLine);

			/// CHECK PAWN
			bool check_root(Pawn* pawn);
			bool check(Pawn* pawn);
			///

			int set_parent(Pawn* parent);
			Pawn* get_parent();

		private:
			std::vector<PawnFrame> m_frames;
			RENDER_ORDER m_renderOrder; // render relative to parent (on top or bottom)
			bool bScaleOffset;

			Pawn* m_parent; // if parent == null, pawn is rendered relative to camera
			std::list<Pawn*> m_children;
	};

	#include "GTS_Pawn.cpp"
}

#endif // GTS_PAWN_H
