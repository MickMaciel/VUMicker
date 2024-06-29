/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
VUMickerAudioProcessorEditor::VUMickerAudioProcessorEditor (VUMickerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    addAndMakeVisible(meterL);
    addAndMakeVisible(meterR);
    startTimerHz(60);

}

VUMickerAudioProcessorEditor::~VUMickerAudioProcessorEditor()
{
}

//==============================================================================
void VUMickerAudioProcessorEditor::timerCallback()
{
    meterL.setLevel(audioProcessor.getRmsValue(0));
    meterR.setLevel(audioProcessor.getRmsValue(1));
    
    meterL.repaint();
    meterR.repaint();
}

void VUMickerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    //g.fillAll(Colours::darkslategrey);

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (21.0f));
    g.drawFittedText ("VU Meter!", getLocalBounds(), juce::Justification:: centred, 1);
}

void VUMickerAudioProcessorEditor::resized()
{
    meterL.setBounds(50, 200, 300, 20);
    meterR.setBounds(50, 230, 300, 20);
}
