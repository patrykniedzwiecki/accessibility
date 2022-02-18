/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ACCESSIBILITY_INPUT_INTERCEPTOR_H
#define ACCESSIBILITY_INPUT_INTERCEPTOR_H

#include <map>
#include <memory>
#include <vector>

#include "event_handler.h"

#include "accessibility_event_transmission.h"
#include "i_input_event_consumer.h"
#include "key_event.h"
#include "pointer_event.h"

namespace OHOS {
namespace Accessibility {
class AccessibleAbilityManagerService;

class AccessibilityInputInterceptor : public EventTransmission {
public:
    // Feature flag for screen magnification.
    const static uint32_t FEATURE_SCREEN_MAGNIFICATION = 0x00000001;

    // Feature flag for touch exploration.
    const static uint32_t FEATURE_TOUCH_EXPLORATION = 0x00000002;

    // Feature flag for filtering key events.
    const static uint32_t FEATURE_FILTER_KEY_EVENTS = 0x00000004;

    // Feature flag for inject touch events.
    const static uint32_t FEATURE_INJECT_TOUCH_EVENTS = 0x00000008;

    static sptr<AccessibilityInputInterceptor> GetInstance();
    ~AccessibilityInputInterceptor();
	static void InterceptPointerEventCallBack(std::shared_ptr<OHOS::MMI::PointerEvent> pointerEvent);
    static void InterceptKeyEventCallBack(std::shared_ptr<OHOS::MMI::KeyEvent> keyEvent);
    void OnKeyEvent(MMI::KeyEvent &event) override;
    void OnPointerEvent(MMI::PointerEvent &event) override;
    void SetAvailableFunctions(uint32_t availableFunctions);
    void NotifyAccessibilityEvent(AccessibilityEventInfo &event) const;

private:
    enum InterceptSourceType {
        MOUSE = 1,
        TOUCHSCREEN,
        TOUCHPAD,
        KEY
    };

    AccessibilityInputInterceptor();
    static sptr<AccessibilityInputInterceptor> instance_;
    void ProcessKeyEvent(std::shared_ptr<MMI::KeyEvent> event);
    void ProcessPointerEvent(std::shared_ptr<MMI::PointerEvent> event);
    void CreateTransmitters();
    void DestroyTransmitters();
    void SetNextEventTransmitter(sptr<EventTransmission> &header, sptr<EventTransmission> &current,
        const sptr<EventTransmission> &next);
    void CreateInterceptors(bool isInterceptPointEvent, bool isInterceptKeyEvent);
    void RemoveAllInterceptors();

    std::shared_ptr<AccessibleAbilityManagerService> ams_ = nullptr;
    sptr<EventTransmission> pointerEventTransmitters_ = nullptr;
    sptr<EventTransmission> keyEventTransmitters_ = nullptr;
    std::shared_ptr<AppExecFwk::EventHandler> eventHandler_ = nullptr;
    uint32_t availableFunctions_ = 0;
    std::map<InterceptSourceType, int32_t> interceptorId_ = {};
};

}  // namespace Accessibility
}  // namespace OHOS
#endif  // ACCESSIBILITY_INPUT_INTERCEPTOR_H