#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Editor/DetailCustomizations/Public/DetailCustomizations.h"
#include "Editor/PropertyEditor/Public/IDetailCustomization.h"
#include "DetailLayoutBuilder.h"
#include "AlpakitSettings.generated.h"

USTRUCT()
struct FAlpakitModDependency
{
	GENERATED_BODY()
	/* mod_reference of your dependency */
    UPROPERTY(EditAnywhere, config)
    FString Mod;

    /* A version constraint (ex. ^2.1.0) */
	UPROPERTY(EditAnywhere, config)
    FString Constraint;
};

USTRUCT()
struct FAlpakitMod
{
	GENERATED_BODY()
	/* Should this mod be paked? */
	UPROPERTY(EditAnywhere, config)
	bool Enabled = true;

	/* mod_reference in data.json, your mod folder name */
	UPROPERTY(EditAnywhere, config)
	FString Name;

	/* The mod name that players see */
	UPROPERTY(EditAnywhere, config)
	FString DisplayName;

	UPROPERTY(EditAnywhere, config)
	FString Description;

	/* Your mod version, format: X.Y.Z */
	UPROPERTY(EditAnywhere, config)
	FString Version;

	UPROPERTY(EditAnywhere, config)
	TArray<FString> Authors;

	/* Mods that are required for running your mod */
	UPROPERTY(EditAnywhere, config)
	TArray<FAlpakitModDependency> Dependencies;
	
	/* Mods that that your mod can integrate with, but are not required */
	UPROPERTY(EditAnywhere, config)
    TArray<FAlpakitModDependency> OptionalDependencies;
	
	/* Can include paths to vanilla assets, or other mod assets that you wish to replace with your version. You don't need to add your mod here */
	UPROPERTY(EditAnywhere, config)
	TArray<FString> OverwritePaths;
};

UCLASS(config = Game)
class UAlpakitSettings : public UObject
{
	GENERATED_BODY()

public:
	UAlpakitSettings(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, config, Category = Config)
	FDirectoryPath SatisfactoryGamePath;
	
	UPROPERTY(EditAnywhere, config, Category = Mods)
	TArray<FAlpakitMod> Mods;

	UPROPERTY(EditAnywhere, config, Category = Config)
	bool StartGame;

	UPROPERTY(EditAnywhere, config, Category = Config)
	bool CopyModsToGame;

};