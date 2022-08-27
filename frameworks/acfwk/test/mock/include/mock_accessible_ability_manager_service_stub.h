/*
 * Copyright (C) 2022 Huawei Device Co., Ltd.
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

#ifndef MOCK_ACCESSIBILITY_ABILITY_MANAGER_SERVICE_CLIENT_STUB_H
#define MOCK_ACCESSIBILITY_ABILITY_MANAGER_SERVICE_CLIENT_STUB_H

#include <map>
#include "i_accessible_ability_manager_service.h"
#include "iremote_stub.h"

namespace OHOS {
namespace Accessibility {
/*
 * The class define the interface to call ABMS API.
 */
class MockAccessibleAbilityManagerServiceStub : public IRemoteStub<IAccessibleAbilityManagerService> {
public:
    MockAccessibleAbilityManagerServiceStub();

    virtual ~MockAccessibleAbilityManagerServiceStub();

    virtual int OnRemoteRequest(
        uint32_t code, MessageParcel &data, MessageParcel &reply, MessageOption &option) override;

    void SendEvent(const AccessibilityEventInfo &uiEvent) override;

    uint32_t RegisterStateObserver(const sptr<IAccessibleAbilityManagerStateObserver> &callback) override;

    uint32_t RegisterCaptionObserver(const sptr<IAccessibleAbilityManagerCaptionObserver> &callback) override;

    void RegisterEnableAbilityListsObserver(
        const sptr<IAccessibilityEnableAbilityListsObserver> &observer) override;

    bool GetAbilityList(const uint32_t abilityTypes, const int32_t stateType,
        std::vector<AccessibilityAbilityInfo> &infos) override;

    void RegisterElementOperator(const int32_t windowId,
        const sptr<IAccessibilityElementOperator> &operation) override;

    void DeregisterElementOperator(const int32_t windowId) override;

    AccessibilityConfig::CaptionProperty GetCaptionProperty() override;
    void SetCaptionProperty(const AccessibilityConfig::CaptionProperty &caption) override;
    void SetCaptionState(const bool state) override;

    bool GetEnabledState() override;
    bool GetCaptionState() override;
    bool GetTouchGuideState() override;
    bool GetGestureState() override;
    bool GetKeyEventObserverState() override;

    bool EnableAbility(const std::string &name, const uint32_t capabilities) override;
    bool GetEnabledAbilities(std::vector<std::string> &enabledAbilities) override;
    bool GetInstalledAbilities(std::vector<AccessibilityAbilityInfo> &installedAbilities) override;

    bool DisableAbility(const std::string &name) override;
    int32_t GetActiveWindow() override;

    RetError EnableUITestAbility(const sptr<IRemoteObject> &obj) override;
    bool DisableUITestAbility() override;

    void SetScreenMagnificationState(const bool state) override;
    void SetShortKeyState(const bool state) override;
    void SetMouseKeyState(const bool state) override;
    void SetMouseAutoClick(const int32_t time) override;
    void SetShortkeyTarget(const std::string &name) override;
    void SetHighContrastTextState(const bool state) override;
    void SetInvertColorState(const bool state) override;
    void SetAnimationOffState(const bool state) override;
    void SetAudioMonoState(const bool state) override;
    void SetDaltonizationColorFilter(const uint32_t filter) override;
    void SetContentTimeout(const uint32_t time) override;
    void SetBrightnessDiscount(const float discount) override;
    void SetAudioBalance(const float balance) override;

    bool GetScreenMagnificationState() override;
    bool GetShortKeyState() override;
    bool GetMouseKeyState() override;
    int32_t GetMouseAutoClick() override;
    std::string GetShortkeyTarget() override;
    bool GetHighContrastTextState() override;
    bool GetInvertColorState() override;
    bool GetAnimationOffState() override;
    bool GetAudioMonoState() override;
    uint32_t GetDaltonizationColorFilter() override;
    uint32_t GetContentTimeout() override;
    float GetBrightnessDiscount() override;
    float GetAudioBalance() override;
    void GetAllConfigs(AccessibilityConfigData &configData) override;
    uint32_t RegisterConfigObserver(const sptr<IAccessibleAbilityManagerConfigObserver> &callback) override;
};
} // namespace Accessibility
} // namespace OHOS
#endif