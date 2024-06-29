#pragma once

#include <JuceHeader.h>


namespace GUI
{
    class GUIMeter : public juce::Component
    {
    public:
        void paint(juce::Graphics& g) override
        {
            auto bounds = getLocalBounds().toFloat();
            
            g.setColour(juce::Colours::grey);
            g.fillRoundedRectangle(bounds, 5.f);
            g.setColour(juce::Colours::greenyellow);
                
            const auto scaledX = juce::jmap(level, -60.f, +6.f, 0.f, static_cast<float>(getWidth()));
            g.fillRoundedRectangle(bounds.removeFromLeft(scaledX), 5.f);
        }
        
        void setLevel(const float value) {level = value; }
        
    private:
        float level = -60.0f;
    };
}
