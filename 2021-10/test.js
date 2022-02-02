function StartStudy() {
    return `The subjects I studied :`;
}

function StudySubject(text, subject) {
    return `${text}\n${subject}`;
}

const TestStudy = () => {
    const text = StartStudy()

    return new Promise((resolve, reject) => {
        if (text) {
            resolve(text);
        } else {
            reject(new Error("We couldn't even start Study!"));
        }
    })
}

const StudyMath = (text) => {
    const newText = StudySubject(text, "Math");

    return new Promise((resolve, reject) => {
        if (newText) {
            resolve(newText);
        } else {
            reject(new Error("We couldn't study Math!"));
        }
    })
}

const StudyEnglish = (text) => {
    const newText = StudySubject(text, "English");

    return new Promise((resolve, reject) => {
        if (newText) {
            resolve(newText);
        } else {
            reject(new Error("We couldn't study English!"));
        }
    })
}

const StudyDone = (text) => {
    const newText = StudySubject(text, "Done!");
    return newText;
}

const Study = () => {
    return TestStudy()
        .then((text) => StudyMath(text))
        .then((text) => StudyEnglish(text))
        .then((text) => StudyDone(text))
        .catch((err) => console.log(`${err}`));
}

function resolvePromise(promise) {
    promise.then((result) => {
        console.log(result);
    });
}

resolvePromise(Study());

// console.log(Study());