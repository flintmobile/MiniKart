//
/*! @file FlintTextField.h */
//  FlintConnect
//
//  Created by PC on 4/7/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FlintTextField;
@protocol FlintTextFieldValidation;

/*!
 *  @enum FlintTextFieldState
 *
 *  @brief The validation state for text field.
 */
typedef NS_ENUM(NSInteger, FlintTextFieldState){
  TextFieldStateValid,      /*!< Valid Validation */
  TextFieldStateInvalid,    /*!< Invalid Validation */
};

/*!
 *  @enum FlintTextFieldValidationMode
 *
 *  @brief The validation mode for text field.
 *
 *  @discussion The validation mode will be reflected on the text return by the delegate call back.
 */
typedef NS_ENUM(NSInteger, FlintTextFieldValidationMode) {
  TextFieldValidationRaw,         /*!< The result come back is raw text */
  TextFieldValidationWithMask     /*!< The result come back is with mask */
};

/*!
 *  @brief Define the format for text field based on different state.
 *
 *  @param textField       The text field
 *  @param validationState The validation state
 */
typedef void(^FlintTextFieldFormatHandler)(FlintTextField *textField, FlintTextFieldState validationState);

/*!
 *  @brief Define the call back after validation.
 *
 *  @param validationState The validation state
 */
typedef void(^FlintTextFieldValidationHandler)(FlintTextFieldState validationState);



/*!
 *  @class FlintTextField
 *
 *  @brief A text field with the option to mask format and validation.
 */
@interface FlintTextField : UITextField

/*!
 *  @brief The masking value, e.g. @"(###)###-####".
 */
@property (copy, nonatomic) NSString *mask;

/*!
 *  @brief The raw / non-mask text value.
 */
@property (copy, nonatomic, readonly) NSString *rawText;

/*!
 *  @brief Specify which value to hand to the validator for validating.
 *
 *  @default TextFieldValidationRaw
 */
@property (assign, nonatomic) FlintTextFieldValidationMode validationMode;

/*!
 *  @brief Specify the validation rule for the text field.
 */
@property (weak, nonatomic) id<FlintTextFieldValidation>validator;

/*!
 *  @brief Different states of the text field.
 *
 *  @default TextFieldStateValid
 */
@property (assign, nonatomic) FlintTextFieldState validationState;

/*!
 *  @brief Formatting the textfield look and feel for different states.
 */
@property (copy, readwrite) FlintTextFieldFormatHandler formatHandler;

/*!
 *  @brief Secure the maskable value with dot and keep format of the mask. e.g. oo/oo/oooo for securing date.
 *
 *  @default NO
 */
@property (assign, nonatomic) BOOL shouldSecureMaskText;

/*!
 *  @brief the length to secure text.
 *
 *  @discussion Specify how much of the string we want to mask. 0 mean mask everything if shouldSecureMaskText set to YES.
 *
 *  @default 0
 */
@property (assign, nonatomic) NSInteger secureMaskLength;

/*!
 *  @brief lock validation delegate call back.
 *
 *  @discussion If this is set to YES, delegate call back for validation won't happen.
 *
 *  @default NO
 */
@property (assign, nonatomic) BOOL validationLock;

/*!
 *  @brief Set the text programatically with masking apply.
 *
 *  @param text the raw text
 */
- (void)applyMaskOnText:(NSString *)text;

/*!
 *  @brief Check validation status.
 *
 *  @discussion Return YES if validation state valid and text field length > 0.
 *
 *  @return NO otherwise
 */
- (BOOL)passValidation;

#pragma mark - Delegate Pipe

/*!
 *  @brief Pipe-through delegate for validation.
 *
 *  @discussion In order for validation to work, text field delegate MUST call this method in textField:shouldChangeCharactersInRange:replacementString:
 *
 *  @param range  the range from the delegate
 *  @param string the string from the delegate
 *
 *  @return YES to receive input, NO to stop
 */
- (BOOL)shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

@end


/*!
 *  @protocol FlintTextFieldValidation
 *
 *  @brief Validating Protocol
 */
@protocol FlintTextFieldValidation <NSObject>

@optional
/*!
 *  @brief Validating the text.
 *
 *  @param textField            the text field
 *  @param text                 depend on validationMode that this supply rawText or maskedText
 *  @param validationCompletion call this when validation complete
 */
- (void)textField:(FlintTextField *)textField validateText:(NSString *)text completion:(FlintTextFieldValidationHandler)validationCompletion;

@end
