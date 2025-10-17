// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections = 4, FString TypeOfMatch = TEXT("FreeForAll"));
protected:
	//In order to bind the button to callbacks we create this function
	virtual bool Initialize() override;
	//This function is called when we travel to another level and is called when is destroyed the level.
	virtual void NativeDestruct() override;

	/*
	 * Callback functions for the custom delegates on the Multiplayer Sessions Subsystems 
	 */
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);
private:
	//Need to be the same name as in the widget variables for buttons
	//This is because of the use of BindWidget meta.
	UPROPERTY(meta=(BindWidget))
	class UButton* HostButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* JoinButton;

	//Calback functions for the buttons
	UFUNCTION()
	void HostButtonClicked();
	
	UFUNCTION()
	void JoinButtonClicked();

	//To Remove the widget and the changes made by MenuSetup() function.
	void MenuTearDown();

	// The subsystem designed to handle all online session functionality.
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	//For parameters in Online Subsystem
	int32 NumPublicConnection{4};
	FString MatchType{TEXT("FreeForAll")};
};
