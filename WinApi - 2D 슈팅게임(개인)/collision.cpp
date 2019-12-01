#include "stdafx.h"
#include "collision.h"

namespace HEXA_UTIL
{
	bool isCollisionReaction(const RECT& rcHold, RECT& rcMove)
	{
		RECT rcInter;

		if (!IntersectRect(&rcInter, &rcHold, &rcMove)) return false;

		int interSectorW = rcInter.right - rcInter.left;
		int interSectorH = rcInter.bottom - rcInter.top;

		//�������� �ε����ٸ�
		if (interSectorW > interSectorH)
		{
			//������ �ھ�����
			if (rcInter.top == rcHold.top)
			{
				//�׸�ŭ �о��
				OffsetRect(&rcMove, 0, -interSectorH);
			}
			else if (rcInter.bottom == rcHold.bottom)
			{
				OffsetRect(&rcMove, 0, interSectorH);
			}
		}
		else//�������� �ھҴٸ�
		{
			//������ �ھ�����
			if (rcInter.left == rcHold.left)
			{
				//�׸�ŭ �о��
				OffsetRect(&rcMove, -interSectorW, 0);
			}
			else if (rcInter.right == rcHold.right)
			{
				OffsetRect(&rcMove, interSectorW, 0);
			}
		}

		return true;
	}


}