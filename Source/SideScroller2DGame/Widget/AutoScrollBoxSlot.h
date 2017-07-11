// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once


#include "SlateWrapperTypes.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "SAutoScrollBox.h"
#include "AutoScrollBoxSlot.generated.h"

/** The Slot for the UScrollBox, contains the widget that are scrollable */
UCLASS()
class SIDESCROLLER2DGAME_API UAutoScrollBoxSlot : public UPanelSlot
{
	GENERATED_UCLASS_BODY()
public:

	/** The padding area between the slot and the content it contains. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout|AutoScrollBox Slot")
		FMargin Padding;

	/** The alignment of the object horizontally. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout|AutoScrollBox Slot")
		TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

public:

	UFUNCTION(BlueprintCallable, Category = "Layout|AutoScrollBox Slot")
		void SetPadding(FMargin InPadding);

	UFUNCTION(BlueprintCallable, Category = "Layout|AutoScrollBox Slot")
		void SetHorizontalAlignment(EHorizontalAlignment InHorizontalAlignment);


public:

	// UPanelSlot interface
	virtual void SynchronizeProperties() override;
	// End of UPanelSlot interface

	/** Builds the underlying FSlot for the Slate layout panel. */
	void BuildSlot(TSharedRef<SAutoScrollBox> ScrollBox);

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

private:
	//TODO UMG Slots should hold weak or shared refs to slots.

	/** A raw pointer to the slot to allow us to adjust the size, padding...etc at runtime. */
	SAutoScrollBox::FSlot* Slot;
};
