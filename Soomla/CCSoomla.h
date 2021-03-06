#ifndef __CCSoomla_H_
#define __CCSoomla_H_

#include "cocos2d.h"
#include "CCEventHandler.h"
#include <vector>

namespace soomla {

    #define SOOMLA_AND_PUB_KEY_DEFAULT "YOUR GOOGLE PLAY PUBLIC KEY"
    #define SOOMLA_ONLY_ONCE_DEFAULT "SET ONLY ONCE"

    using namespace std;

	/** \class CCSoomla
		\brief Calls event handler functions when events are fired, also contains settings for StoreController.

		This class calls event handler functions when events are fired, to tie
		it to your event handler call addEventHandler(). You also set parameters
		for StoreController through this class.
	 */
    class CCSoomla: public cocos2d::CCObject {
        CC_SYNTHESIZE(string, mCustomSecret, CustomSecret);
        CC_SYNTHESIZE(string, mAndroidPublicKey, AndroidPublicKey);
        CC_SYNTHESIZE(bool, mAndroidTestMode, AndroidTestMode);
        CC_SYNTHESIZE(string, mSoomSec, SoomSec);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        CC_SYNTHESIZE(bool, mSSV, SSV);
#endif

	private:
		set<CCEventHandler *> mEventHandlers;

    public:
		/**
		   This class is singleton, access it with this function.
		 */
        static CCSoomla* sharedSoomla();

        CCSoomla():
            mCustomSecret(SOOMLA_ONLY_ONCE_DEFAULT),
            mAndroidPublicKey(SOOMLA_AND_PUB_KEY_DEFAULT),
            mAndroidTestMode(false),
            mSoomSec(SOOMLA_ONLY_ONCE_DEFAULT)
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            ,mSSV(false)
#endif
        {};
        virtual ~CCSoomla(void);
        virtual bool init(void);

		/**
		   Call an NDK function by name and parameters.
		   \param parameters A dictionary containing the function to call and parameters to pass to it.
		 */
        void easyNDKCallBack(cocos2d::CCDictionary *parameters);

		/**
		   Add an event handler.
		   \param eventHandler A pointer to the event handler you'd like to add.
		 */
		void addEventHandler(CCEventHandler *eventHandler);

		/**
		   Remove an event handler.
		   \param eventHandler A pointer to the event handler you'd like to remove.
		*/
		void removeEventHandler(CCEventHandler *eventHandler);
		
    };
};

#endif //__CCSoomla_H_
