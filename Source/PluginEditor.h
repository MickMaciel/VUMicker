/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUIMeter.h"

//==============================================================================

class VUMickerAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Timer
{
public:
    VUMickerAudioProcessorEditor (VUMickerAudioProcessor&);
    ~VUMickerAudioProcessorEditor() override;
    

    //==============================================================================
    void timerCallback() override;
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    VUMickerAudioProcessor& audioProcessor;
    
    GUI::GUIMeter meterL, meterR;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VUMickerAudioProcessorEditor)
};
