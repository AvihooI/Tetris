//
// Created by Avihoo on 26/06/2020.
//

#include "animation.h"

void animationTick()
{
	if (animationState.ongoing)
	{
		animationState.ticksRemaining--;

		if (animationState.ticksRemaining == 0)
		{
			animationState.ongoing = 0;
			gameState.reducedLinesCount = 0;
		}
	}
	else if (!animationState.ongoing && gameState.reducedLinesCount > 0)
	{
		animationState.ticksRemaining = ANIMATION_TICKS;
		animationState.ongoing = 1;
	}

}

void initAnimation()
{
	animationState.ongoing = 0;
	animationState.ticksRemaining = 0;
}
