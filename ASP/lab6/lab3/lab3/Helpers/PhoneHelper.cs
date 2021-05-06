using PhoneDictionary;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace lab3.Helpers
{
    public static class PhonesHelper
    {
        public static MvcHtmlString AddPhoneForm(this HtmlHelper html)
        {
            TagBuilder form = new TagBuilder("form");
            form.MergeAttribute("method", "post");
            form.MergeAttribute("action", "/Dict/Add");

            TagBuilder NameInputWrapper = new TagBuilder("div");
            TagBuilder NameInput = new TagBuilder("input");
            NameInput.MergeAttribute("type", "text");
            NameInput.MergeAttribute("name", "Name");
            NameInput.MergeAttribute("placeholder", "Name");
            NameInputWrapper.InnerHtml = NameInput.ToString();

            TagBuilder phoneInputWrapper = new TagBuilder("div");
            TagBuilder phoneInput = new TagBuilder("input");
            phoneInput.MergeAttribute("type", "text");
            phoneInput.MergeAttribute("name", "PhoneNumber");
            phoneInput.MergeAttribute("placeholder", "PhoneNumber");
            phoneInputWrapper.InnerHtml = phoneInput.ToString();

            TagBuilder submitButtonWrapper = new TagBuilder("div");
            TagBuilder submitButton = new TagBuilder("button");
            submitButton.MergeAttribute("type", "submit");
            submitButton.SetInnerText("Add");
            submitButtonWrapper.InnerHtml = submitButton.ToString();

            form.InnerHtml = NameInputWrapper.ToString() + phoneInputWrapper.ToString() + submitButtonWrapper.ToString();
            return new MvcHtmlString(form.ToString());
        }

        public static MvcHtmlString UpdatePhoneForm(this HtmlHelper html, object newPhone)
        {
            PhoneNote phone = newPhone as PhoneNote;
            TagBuilder form = new TagBuilder("form");
            form.MergeAttribute("method", "post");
            form.MergeAttribute("action", "/dict/edit/"  + phone.Id);

            TagBuilder idInput = new TagBuilder("input");
            idInput.MergeAttribute("type", "hidden");
            idInput.MergeAttribute("name", "Id");
            idInput.MergeAttribute("value", phone.Id.ToString());


            TagBuilder NameInputWrapper = new TagBuilder("div");
            TagBuilder NameInput = new TagBuilder("input");
            NameInput.MergeAttribute("type", "text");
            NameInput.MergeAttribute("name", "Name");
            NameInput.MergeAttribute("value", phone.Name);
            NameInput.MergeAttribute("placeholder", "Name");
            NameInputWrapper.InnerHtml = NameInput.ToString();

            TagBuilder phoneInputWrapper = new TagBuilder("div");
            TagBuilder phoneInput = new TagBuilder("input");
            phoneInput.MergeAttribute("type", "text");
            phoneInput.MergeAttribute("name", "PhoneNumber");
            phoneInput.MergeAttribute("value", phone.PhoneNumber.ToString());
            phoneInput.MergeAttribute("placeholder", "PhoneNumber");
            phoneInputWrapper.InnerHtml = phoneInput.ToString();

            TagBuilder submitButtonWrapper = new TagBuilder("div");
            TagBuilder submitButton = new TagBuilder("button");
            submitButton.MergeAttribute("type", "submit");
            submitButton.SetInnerText("Обновить");
            submitButtonWrapper.InnerHtml = submitButton.ToString();

            form.InnerHtml = idInput.ToString() + NameInputWrapper.ToString() + phoneInputWrapper.ToString() + submitButtonWrapper.ToString();
            return new MvcHtmlString(form.ToString());
        }

    }
}