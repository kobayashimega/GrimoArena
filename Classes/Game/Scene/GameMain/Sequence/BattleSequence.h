#ifndef BATTLESEQUENCE_H
#define BATTLESEQUENCE_H

#include "ISequence.h"

class BattelSequence : public ISequence
{
public:
	BattelSequence(StageManager* stageManager);
	~BattelSequence();

	S_STATUS update(float at) override;					//�X�V

	void main(float at) override;						//���C���X�V

	void start(float at) override;						//�V�[�N�G���X����

	void end(float at) override;						//�V�[�N�G���X�I���

	void onEndSequence() override;

	/*----------------------------------------------------------------------
	|	�E�^�b�`�n��
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;

	/*----------------------------------------------------------------------
	|	�E�^�b�`�I���
	----------------------------------------------------------------------*/
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;

};

#endif