#pragma once
#include "syati.h"
#include "Game/NPC/EventDirector.h"
#include "Game/Effect/EffectSystemUtil.h"
#include "Game/System/ResourceHolderManager.h"
#include "Game/System/GameEventFlagTable.h"

namespace pt
{
    extern void* loadArcAndFile(const char *pArc, const char *pFile, JKRHeap *pHeap);
}

namespace sf
{
    bool isFlagActive(const char *pFlagName);
    bool isFlagActive(s32 index);
    bool isFlagActive(JMapInfoIter iter);
    
    const char *getParamStrNumbered(JMapInfoIter iter, int index);
    s32 getLife();
    bool handleTypeAnd(JMapInfoIter iter);
    bool handleTypeOr(JMapInfoIter iter);
    bool handleTypeNot(JMapInfoIter iter);
    bool handleTypeGalaxyName(JMapInfoIter iter);
    bool handleTypeScenarioNo(JMapInfoIter iter);
    bool handleTypeSelectedScenarioNo(JMapInfoIter iter);
    bool handleTypePowerStarNum(JMapInfoIter iter);
    bool handleTypeStockedCoinNum(JMapInfoIter iter);
    bool handleTypeStockedStarPieceNum(JMapInfoIter iter);
    bool handleTypeStarPieceNum(JMapInfoIter iter);
    bool handleTypeCoinNum(JMapInfoIter iter);
    bool handleTypePurpleCoinNum(JMapInfoIter iter);
    bool handleTypeClearTime(JMapInfoIter iter);
    bool handleTypeTicoCoinNum(JMapInfoIter iter);
    bool handleTypeLivesNum(JMapInfoIter iter);
    bool handleTypeLifeNum(JMapInfoIter iter);
    bool handleTypeRaceTime(JMapInfoIter iter);
    bool handleTypeBronzeStarCollected(JMapInfoIter iter);
    bool handleTypeStarCollected(JMapInfoIter iter);
    bool handleTypeTicoCoinCollected(JMapInfoIter iter);
    bool handleTypeGameEventFlag(JMapInfoIter iter);
    bool handleTypeGalaxyCompletedNoGreen(JMapInfoIter iter);
    bool handleTypeGalaxyCompletedWithGreen(JMapInfoIter iter);

    struct ConditionEntry {
        const char* flagType;
        bool (*func)(JMapInfoIter iter);
    };

    static const ConditionEntry gConditionTable[] = {
        {"And", handleTypeAnd},
        {"Or", handleTypeOr},
        {"Not", handleTypeNot},
        {"GalaxyName", handleTypeGalaxyName},
        {"ScenarioNo", handleTypeScenarioNo},
        {"ScenarioNum", handleTypeScenarioNo},
        {"SelectedScenarioNo", handleTypeSelectedScenarioNo},
        {"SelectedScenarioNum", handleTypeSelectedScenarioNo},
        {"PowerStarNum", handleTypePowerStarNum},
        {"StockedCoinNum", handleTypeStockedCoinNum},
        {"StockedStarPieceNum", handleTypeStockedStarPieceNum},
        {"StockedStarBitNum", handleTypeStockedStarPieceNum},
        {"StarPieceNum", handleTypeStarPieceNum},
        {"StarBitNum", handleTypeStarPieceNum},
        {"CoinNum", handleTypeCoinNum},
        {"PurpleCoinNum", handleTypePurpleCoinNum},
        {"ClearTime", handleTypeClearTime},
        {"TicoCoinNum", handleTypeTicoCoinNum},
        {"CometMedalNum", handleTypeTicoCoinNum},
        {"MarioLeftNum", handleTypeLivesNum},
        {"LivesNum", handleTypeLivesNum},
        {"HealthLeftNum", handleTypeLifeNum},
        {"LifeMeterNum", handleTypeLifeNum},
        {"RaceTime", handleTypeRaceTime},
        {"BronzeStarCollected", handleTypeBronzeStarCollected},
        {"StarCollected", handleTypeStarCollected},
        {"TicoCoinCollected", handleTypeTicoCoinCollected},
        {"CometMedalCollected", handleTypeTicoCoinCollected},
        {"GameEventFlag", handleTypeGameEventFlag},
        {"GalaxyCompletedSilver", handleTypeGalaxyCompletedNoGreen},
        {"GalaxyCompletedNoGreen", handleTypeGalaxyCompletedNoGreen},
        {"GalaxyCompletedGold", handleTypeGalaxyCompletedWithGreen},
        {"GalaxyCompletedWithGreen", handleTypeGalaxyCompletedWithGreen},
        {{CustomFlagConditionals}}
    };

    const size_t gConditionTableEntries = sizeof(gConditionTable)/sizeof(gConditionTable[0]);

    enum Comparator
    {
        Greater,
        GreaterEqual,
        Equal,
        NotEqual,
        Less,
        LessEqual,
        InvalidComparator
    };

    static const char *sComparators[] = {">", ">=", "==", "!=", "<", "<="};
    
    Comparator getComparatorType(const char *pString);
    bool compareValues(Comparator comp, s32 val1, s32 val2);
    bool handleTypeGroupComparisonS32(JMapInfoIter iter, s32 val);

    {{Externs}}
}