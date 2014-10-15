```flow
st=>start: Start
e=>end
op=>operation: My Operation
cond=>condition: Yes or No?
essai=>condition: oui non ?

st->op->cond
cond(yes)->essai
cond(no)->op
essai(yes)->e
essai(no)->e

```