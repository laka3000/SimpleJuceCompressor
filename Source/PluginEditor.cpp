/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CompressorAudioProcessorEditor::CompressorAudioProcessorEditor (CompressorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize(900, 300);

	gainSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	gainSlider.setRange(-70.0, 6.0, 0.01);
	gainSlider.setValue(-1.0);
	gainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 30);

	thresholdSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	thresholdSlider.setRange(-70.0, 6.0, 0.01);
	thresholdSlider.setValue(0.0);
	thresholdSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 30);

	ratioSlider.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	ratioSlider.setRange(1.0, 100.0, 0.01);
	ratioSlider.setValue(0.0);
	ratioSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 30);

	addAndMakeVisible(gainSlider);
	addAndMakeVisible(thresholdSlider);
	addAndMakeVisible(ratioSlider);

	gainSlider.addListener(this);
	thresholdSlider.addListener(this);
	ratioSlider.addListener(this);
}

CompressorAudioProcessorEditor::~CompressorAudioProcessorEditor()
{
}

//==============================================================================
void CompressorAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void CompressorAudioProcessorEditor::resized()
{
	gainSlider.setBounds(0, 0, 300, 300);
	thresholdSlider.setBounds(325, 0, 300, 300);
	ratioSlider.setBounds(725, 0, 100, 300);
}

void CompressorAudioProcessorEditor::sliderValueChanged(Slider *slider) {
	if (slider == &gainSlider)
		processor.incomingGain = gainSlider.getValue();
	else if (slider == &thresholdSlider)
		processor.incomingThreshold = thresholdSlider.getValue();
	else if (slider == &ratioSlider)
		processor.incomingRatio = ratioSlider.getValue();
}
