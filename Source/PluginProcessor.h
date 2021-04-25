/*
	==============================================================================

		This file was auto-generated!

		It contains the basic framework code for a JUCE plugin processor.

	==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <juce_dsp/juce_dsp.h>


//==============================================================================
/**
*/
class MisstortionAudioProcessor : public AudioProcessor
{
public:
	AudioParameterFloat* m_paramMix;
	AudioParameterFloat* m_paramGainIn;
	AudioParameterFloat* m_paramGainOut;

	AudioParameterFloat* m_paramDriveHard;
	AudioParameterFloat* m_paramDriveSoft;
	AudioParameterInt* m_paramToneHP;
	AudioParameterInt* m_paramToneLP;
	AudioParameterFloat* m_paramSymmetry;
	AudioParameterInt* m_paramFilterMode;

	typedef dsp::ProcessorDuplicator<
		dsp::IIR::Filter<float>,
		dsp::IIR::Coefficients<float>
	> FilterType;

	FilterType m_filterHP;
	FilterType m_filterLP;

	// Legacy filters (1 per channel)
	IIRFilter m_filtersHPLegacy[2];
	IIRFilter m_filtersLPLegacy[2];

#if DEBUG
	String m_debugText;
#endif

public:
	//==============================================================================
	MisstortionAudioProcessor();
	~MisstortionAudioProcessor();

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(AudioSampleBuffer&, MidiBuffer&) override;

	//==============================================================================
	AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const String getProgramName(int index) override;
	void changeProgramName(int index, const String& newName) override;

	//==============================================================================
	void getStateInformation(MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MisstortionAudioProcessor)
};
